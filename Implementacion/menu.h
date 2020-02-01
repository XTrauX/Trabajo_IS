#ifndef MENU_H
#define MENU_H


#include "paciente.h"
#include <list>
#include <string>

using namespace std;

struct Cita_dia{
  string nombre_;
  string apellidos_;
  string hora_;
};

class Menu{

private:

  list<Paciente> pacientes_;
  list<Cita_dia> citas_diarias_;

  void Modificar_Paciente(Paciente &p);
  void Modificar_Cita(Paciente &p);
  void Modificar_Tratamiento(Paciente &p);
  void Consultar_Paciente(Paciente &p);
  bool Consultar_Lista_Pacientes();
  void Consultar_Citas(Paciente &p);
  void Consultar_Tratamientos(Paciente &p);
  void Consultar_Historial(Paciente &p);
  bool loadPacientes();
  bool savePacientes();
  bool saveHistoriales();
  Paciente Buscar_Paciente();
  bool Add_Paciente();
  void Consultar_Citas_Diarias();
  void menu_principal();
  void menu_paciente();
  void menu_mod_paciente();
  void menu_mod_cita();
  void menu_mod_tratamiento();
  //bool cmpHora(const Cita_dia &first, const Cita_dia &second);

public:

  void execute();

};

#endif
