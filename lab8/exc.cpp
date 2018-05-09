/* THIS FILE CAN'T BE CHANGED. Below is description in Polish */

// Obsluga wyjatkow
//
// Nalezy napisac klase wyjatku tak by ponizszy kod zadzialal poprawnie.
//
// Dodatkowo nalezy napisac uchwyt obslugujacy wyjatki i wypisujacy informacje o wyjatku i jego przyczynach.
//
// Kompilowac z opcja -Wall -g do pliku wyk. o nazwie "exc".
// Prosze nie zmieniac nazwy tego pliku (ma byc exc.C)
// ani nie kopiowac do innego uwuwajac komentarze (zmienia sie wtedy numery linii w makrze __LINE__).

// UWAGA: Prosze zauwazyc ze wyrzucane sa wkazniki. To powinno pozwolic na "przechowanie" jednego wyjatku w drugim.
//

#include <iostream>
#include "myerrors.h"
#include "myerrors.h"
using namespace std;


struct m {
  static void step1() {
    throw new std::runtime_error("Very serious issue in 1");
  }

  static void step2() {
    try {
      std::cout << "Step 2" << std::endl;
      m::step1();
    } catch (const std::runtime_error* err) {
      throw new myerrors::calc_error(err, "exception from step2", __FILE__, __LINE__);
    }
  }

  static void step3() {
    try {
      std::cout << "Step 3" << std::endl;
      step2();
    } catch (const std::runtime_error* err) {
      throw new myerrors::calc_error(err, "exception from step3", __FILE__, __LINE__);
    }
  }

  static void my_calculations(int arg) {
    try {
      std::cout << "Step 4" << std::endl;
      step3();
    } catch (const std::runtime_error* err) {
      throw new myerrors::calc_error(err, "my_calculations", __FILE__, __LINE__);
    }
  }
};




int main(int argc, char** argv) {
  try {
    m::my_calculations(1);
    throw new std::runtime_error("end");
  } catch (...) {
    myerrors::handler();
  }
}
/* result:

Step 4
Step 3
Step 2
Exception in: my_calculations [in file: exc.cpp in line: 47]
because of : exception from step3 [in file: exc.cpp in line: 38]
because of : exception from step2 [in file: exc.cpp in line: 29]
because of : Very serious issue in 1
*/
