#include "paciente.h"
#include "fecha.h"
#include <string>
#include <iostream>

using namespace std;
/*
int main(int argc, char const *argv[]) {
  Paciente pac("AA", "BB", 0);
  cout << "zorra"<<endl;
  return 0;
}
*/

int main(int argc, char const *argv[]) {
  string fecha1;
  fecha1= "99/99/9999";
  int x;
  x=cmpFecha(fecha1,getSysFecha());
  cout << x;
  return 0;
}
