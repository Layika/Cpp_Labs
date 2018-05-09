/* THIS FILE CAN'T BE CHANGED. Below is description in Polish */

/*
   Celem zadania jest napisanie pomocniczej klasy DoUndo, ktora pozwala
   na odwolanie operacji.

   Jak to jest robione powinno byc ewidentne po przeczytaniu zawartosci klasy Msg.

   UWAGA: Prosze zauwazyc ze w trFail ostania funkcja statyczna
   DoUndo::allok() nie jest wywolywana, jest to f. statyczna!

   UWAGA: KeepInt musi przechowac zarowno wartosc poczatkow jak i
   referencje do miejsca gdzie mozna odlozyc te wartosc jesli undo jest wolane.
 */
 
#include <iostream>
#include <stdexcept>
#include "DoUndo.h"


class Msg : public DoUndoAction {
  void dodo() {
    std::cout << "Entering transaction" << std::endl;
  }
  void undoOk() {
    std::cout << "Finished transaction" << std::endl;
  }
  void undoFail() {
    std::cout << "Broken transaction" << std::endl;
  }

};

int account1 = 100;
int account2 = 20;

void trOK() {
  DoUndo msg(new Msg());
  const int wartoscPrzelewu = 11;
  DoUndo a1(new KeepInt(account1)); // trick w tym zadaniu jest tutaj, musimy przechowac referencje do int: account1 aby, moc potencjalnie zmienic jego wartosc gdy transakcja si enie powiedzie
  DoUndo a2(new KeepInt(account2));
  account1 -= wartoscPrzelewu;
  account2 += wartoscPrzelewu;
  DoUndo::allok();


}


void trFail() {
  DoUndo msg(new Msg());
  const int wartoscPrzelewu = 14;
  DoUndo a1(new KeepInt(account1));
  DoUndo a2(new KeepInt(account2));
  account1 -= wartoscPrzelewu;
  throw std::runtime_error("Transaction cancelled for unknown reason");
  account2 += wartoscPrzelewu;
  DoUndo::allok();
}


int main() {
  try {
    trOK();
    std::cout  << "account1 " << account1 << " account2 " << account2 << std::endl;
    trFail();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout  << "account1 " << account1 << " account2 " << account2 << std::endl;
  }

}
/* result:
Entering transaction
Finished transaction
account1 89 account2 31
Entering transaction
Broken transaction
Transaction cancelled for unknown reason
account1 89 account2 31
 */
