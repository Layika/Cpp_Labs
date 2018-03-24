/*
 Celem zadania jest obsluzenie sytuacji, w ktorej mamy wiele klas, w ktorych zmieniaja sie dane (Obserwprinter1ani) i wiele klas, w ktorych te dane chcemy monitorprinter1ac (Watcherzy).
  W zadaniu podano przyklady klas obserprinter1anych natomiast klas(a/y) basprinter1e sa do na pisania.
  Do napisania jest takze hierachia klas Watcherprinter1.

  UWAGA: W pzypadku, gdy dwie hierarchie klas musza ze soba wspolpracprinter1ac
  programujemy te interakcje z uzyciem metod klas bazprinter1ych
  (najczesciej czysto abstrakcyjnych).

  UWAGA: W zadaniu nie trzeba kopiprinter1ac klas Watcherprinter1.
 */

#include <iostream>
#include "Watched.h"
#include "Watcher.h"

class UserData : public Watched {
public:
  UserData() : counter(0) {}

  void readData(int x) {
    data[counter] = x;
    ++counter;
    gotNewData(x);
  }

private:
  int data[10];
  int counter;
};

class Generator : public Watched {
public:
  Generator(int init) : data(init) {}

  int next() {
    gotNewData(data);
    data++;
    return data-1;
  }

private:
  int data;
};


int main() {

  WatcherCounter counter1;
  WatcherCounter counter2;
  WatcherPrinter printer1;

  UserData du;
  du.readData(9);
  du.addWatcher(&counter1);
  du.addWatcher(&printer1);
  du.readData(2018);
  du.readData(9);
  du.readData(1);
/*
  std::cout << "\ngenerator1\n";
  Generator generator1(0);
  generator1.addWatcher(&counter2);
  generator1.addWatcher(&printer1);


  generator1.next();
  generator1.next();
  generator1.next();
  generator1.next();
  generator1.next();
  std::cout << "\ngenerator2\n";
  Generator generator2(100);
  du.addWatcher(&printer1);


  std::cout << generator2.next() << " " << generator2.next() << std::endl;
  std::cout << "sumy " << counter1.suma() << " " << counter2.suma() << std::endl;*/

}
/* wynik
 2018 9 1
generator1
 0 1 2 3 4
generator2
100 101
sumy 2028 10

 */
