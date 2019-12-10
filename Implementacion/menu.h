#ifndef MENU_H
#define MENU_H

//WORK IN PROGRESS

#include "paciente.h"
#include <list>
#include <string>

using namespace std;

class Menu{

private:

  list<Paciente> pacientes_;
  list<string> nombre_pacientes;

public:

  bool modificar_paciente();
  void consultar_paciente();
  bool consultar_lista_pacientes();
  string buscar_paciente();
  bool add_paciente();

};

#endif
