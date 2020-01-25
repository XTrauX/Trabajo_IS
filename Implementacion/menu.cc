#include "menu.h"
#include "paciente.h"
#include "cita.h"
#include "tratamiento.h"
#include "historial_medico.h"
#include "linea_medico.h"
#include "fecha.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool cmpHora(const Cita_dia &first, const Cita_dia &second)
{
  int hora1, hora2;
  hora1=stoi(first.hora_.substr(0,2))*60+stoi(first.hora_.substr(3,2));
  hora2=stoi(second.hora_.substr(0,2))*60+stoi(second.hora_.substr(3,2));
  return hora1<=hora2?true:false;
}
void Menu::execute()
{
  string opcion;
  bool ctrl1=true, ctrl2, aux;
  Paciente pac("AA","BB",0);
  while(ctrl1)
  {
    ctrl2=true;
    menu_principal();
    cout << "Introduzca la opcion deseada: ";
    cin >> opcion;
    switch (stoi(opcion)) {
      case 1:
        Consultar_Citas_Diarias();

        break;
      case 2:
        Consultar_Lista_Pacientes();
        break;
      case 3:
        pac=Buscar_Paciente();
        if(pac.getNombre()=="XX")
        {
          cout << "No se ha encontrado el paciente."<<endl;
          break;
        }
        while(ctrl2)
        {
          cout << "\t" << pac.getNombre() << " " << pac.getApellidos() << endl;
          menu_paciente();
          cout << "Introduzca la opcion deseada: ";
          cin >> opcion;
          switch (stoi(opcion)) {
            case 1:
              Consultar_Paciente(pac);
              break;
            case 2:
              Consultar_Citas(pac);
              break;
            case 3:
              Consultar_Tratamientos(pac);
              break;
            case 4:
              Consultar_Historial(pac);
              break;
            case 5:
              ctrl2=false;
              break;
            default:
              break;
          }
        }
        break;
      case 4:
        aux=Add_Paciente();
        break;
      case 5:
        ctrl1=false;
        break;
    }
  }
}
void Menu::Consultar_Paciente(Paciente &p)
{
  loadPacientes();
  char opcion;
  cout << "Datos de " << p.getNombre() << " " << p.getApellidos()
  << endl << "Fecha Nacimiento:\t" << p.getFechaNacimiento()
  << endl << "Teléfono móvil:\t\t" << p.getTelefono()
  << endl << "Dirección postal:\t" << p.getDireccionPostal()
  << endl << "Seguro de Salud:\t" << p.getSeguroSalud()
  << endl << "--------------------------------"
  << endl << "¿Desea modificar algun dato? (y/n)"
  << endl << "--------------------------------"
  << endl;
  cin >> opcion;
  if(opcion=='y')
    Modificar_Paciente(p);

}
void Menu::Consultar_Citas(Paciente &p)
{
  p.loadCitas();
  list<Cita> c=p.getCitas();
  char opcion;
  cout << "Citas de " << p.getNombre() << " " << p.getApellidos() << endl;
  for(list<Cita>::iterator it = c.begin(); it!=c.end(); ++it)
  {
    cout << it->getIdCita() << "\t" << it->getFecha() << " " << it->getHora() << "\tDuración: " << it->getDuracion() << endl;
  }
  cout << "--------------------------------"
  << endl << "¿Desea modificar o añadir alguna cita? (y/n)"
  << endl << "--------------------------------"
  << endl;
  cin >> opcion;
  if(opcion=='y')
    Modificar_Cita(p);

}
void Menu::Consultar_Tratamientos(Paciente &p)
{
  p.loadTratamientos();
  list<Tratamiento> t=p.getTratamientos();
  char opcion;
  cout << "Tratamientos de " << p.getNombre() << " " << p.getApellidos() << endl;
  for(list<Tratamiento>::iterator it = t.begin(); it!=t.end(); ++it)
  {
    cout << it->getIdTratamiento() << "\t" << it->getMedicamento()
    << endl << "\tFecha de incio: " << it->getFechaInicio() << "\tDuración: " << it->getDuracion()
    << endl << "\tRegularidad: " << it->getRegularidad() << "\tConcentración: " << it->getConcentracion()
    << endl << "\tAnotación: " <<it->getNotas() << endl;
  }
  cout << "--------------------------------"
  << endl << "¿Desea modificar o añadir algun tratamiento? (y/n)"
  << endl << "--------------------------------"
  << endl;
  cin >> opcion;
  if(opcion=='y')
    Modificar_Tratamiento(p);

}
void Menu::Consultar_Historial(Paciente &p)
{
  string opcion;
  p.loadHistorial();
  Historial h;
  h=p.getHistorial();
  list<Linea> l=h.getLinea();
  cout << "Historial médico de " << p.getNombre() << " " << p.getApellidos() << endl << "Fecha de alta: " << h.getFechaAlta() << endl;
  for(list<Linea>::iterator it = l.begin(); it!= l.end(); ++it)
  {
    cout << it->getNumeroLinea() << " " << it->getFecha()
    << endl << "\t" << it->getComentario() <<endl;
  }
  cout << "--------------------------------"
  << endl << "¿Desea añadir alguna linea de historial? (y/n)"
  << endl << "--------------------------------"
  << endl;
  cin >> opcion;
  if(opcion=='y')
  {

  }
}
bool Menu::Consultar_Lista_Pacientes()
{
  cout << "------------------------" << endl;
  if(loadPacientes())
  {
    for(list<Paciente>::iterator it = pacientes_.begin(); it != pacientes_.end(); ++it)
    {
      cout << it->getNombre() << " " << it->getApellidos() << "\tTelefono: " << it->getTelefono()<<endl;
    }
  }
  else
    cout << "No hay pacientes en la base de datos." << endl;
  cout << "------------------------" << endl;

}
Paciente Menu::Buscar_Paciente()
{
  string nombre, apellido1, apellido2, apellidos;
  Paciente error("XX","YY",0);
  if(loadPacientes())
  {
    cout << "Introduzca el primer nombre del paciente a buscar: ";
    cin >> nombre;
    cout << "Introduzca los apellidos del paciente"
    << endl << "Primer apellido: ";
    cin >> apellido1;
    cout << "Segundo apellido: ";
    cin >> apellido2;
    apellidos= apellido1 + " " + apellido2;
    cout << "Buscando ..." << endl;
    for(list<Paciente>::iterator it = pacientes_.begin(); it != pacientes_.end(); ++it)
    {
      if(nombre==it->getNombre()&&apellidos==it->getApellidos())
        return *it;
      }
  }
  return error;
}
void Menu::Modificar_Paciente(Paciente &p)
{
  int opcion, x;
  bool ctrl=true, borrar=false;
  string dato;
  Paciente aux=p;
  while(ctrl)
  {
    menu_mod_paciente();
    cout<< "¿Que desea hacer? ";
    cin >> opcion;
    switch (opcion) {
      case 1:
        cout << "Introduzca el nuevo teléfono: ";
        cin >>dato;
        x=stoi(dato);
        if(!aux.setTelefono(x))
          cout << "Numero introducido incorrecto." << endl;
        break;
      case 2:
        cout << "Introduzca la nueva dirección: ";
        cin >>dato;
        x=stoi(dato);
        if(!aux.setDireccionPostal(x))
          cout << "Dirección postal incorrecta." << endl;
        break;
      case 3:
        cout << "Introduzca el nuevo seguro de salud: ";
        cin >>dato;
        aux.setSeguroSalud(dato);
        break;
      case 4:
        ctrl=false;
        borrar=true;
        break;
      case 5:
        ctrl=false;
        break;
    }
  }
  for(list<Paciente>::iterator it = pacientes_.begin();it!=pacientes_.end(); ++it)
  {
    if(it->getNombre()==p.getNombre() && it->getApellidos()==p.getApellidos())
    {
      if(borrar)
      {
        it->loadCitas();
        it->loadTratamientos();
        it->citas_.clear();
        it->tratamientos_.clear();
        it->saveCitas();
        it->saveTratamientos();
        pacientes_.erase(it);
        savePacientes();
        execute();
      }
      else
        *it=aux;
        p=aux;
      break;
    }
  }
  savePacientes();
}
void Menu::Modificar_Cita(Paciente &p)
{
  int opcion, x;
  string aux;
  bool ctrl=true;
  Cita c(0);
  while(ctrl)
  {
    menu_mod_cita();
    cin >> opcion;
    switch (opcion) {
      case 1:
        cout << "Introduzca el numero de cita que quiera cambiar: ";
        cin >> aux;
        x=stoi(aux);
        c.setIdCita(x);
        cout << "Introduzca la fecha de la cita (dd/mm/yyyy): ";
        cin >> aux;
        c.setFecha(aux);
        if(cmpFecha(aux,getSysFecha())==0) citas_diarias_.clear();
        cout << "Introduzca la hora de la cita (hh:mm): ";
        cin >> aux;
        c.setHora(aux);
        cout << "Introduzca la duracion de la cita (en minutos): ";
        cin >> aux;
        x=stoi(aux);
        c.setDuracion(x);
        p.modifyCita(c);
        break;
      case 2:
        cout << "Introduzca la fecha de la cita (dd/mm/yyyy): ";
        cin >> aux;
        c.setFecha(aux);
        if(cmpFecha(aux,getSysFecha())==0) citas_diarias_.clear();
        cout << "Introduzca la hora de la cita (hh:mm): ";
        cin >> aux;
        c.setHora(aux);
        cout << "Introduzca la duracion de la cita (en minutos): ";
        cin >> aux;
        x=stoi(aux);
        c.setDuracion(x);
        p.addCita(c);
        break;
      case 3:
        cout << "Introduzca el numero de cita a eliminar: ";
        cin >> aux;
        x=stoi(aux);
        p.eraseCita(x);
        ctrl=false;
        break;
      case 4:
        ctrl=false;
        break;
    }
  }

}
void Menu::Modificar_Tratamiento(Paciente &p)
{
  int opcion, x;
  string aux;
  bool ctrl=true;
  Tratamiento t;
  while(ctrl)
  {
    menu_mod_tratamiento();
    cin >> opcion;
    switch (opcion) {
      case 1:
        cout << "Introduzca el numero de tratamiento que desea cambiar: ";
        cin >> aux;
        x=stoi(aux);
        t.setIdTratamiento(x);
        cout << "Introduzca el medicamento: ";
        cin >>  aux;
        t.setMedicamento(aux);
        cout << "Introduzca la concentracion de la dosis: ";
        cin >> aux;
        t.setConcentracion(stof(aux));
        cout << "Introduzca las veces al dia de medicación: ";
        cin >> aux;
        x=stoi(aux);
        t.setRegularidad(x);
        cout << "Introduzca la fecha de inicio(dd/mm/yyyy): ";
        cin >> aux;
        t.setFechaInicio(aux);
        cout << "Introduzca el numero de dias que se debe medicar: ";
        cin >> aux;
        x=stoi(aux);
        t.setDuracion(x);
        cout << "Introduzca alguna nota adicional: ";
        cin.ignore();
        getline(cin,aux);
        t.setNotas(aux);
        p.modifyTratamiento(t);
        break;
      case 2:
        cout << "Introduzca el medicamento: ";
        cin >>  aux;
        t.setMedicamento(aux);
        cout << "Introduzca la concentracion de la dosis: ";
        cin >> aux;
        t.setConcentracion(stof(aux));
        cout << "Introduzca las veces al dia de medicación: ";
        cin >> aux;
        x=stoi(aux);
        t.setRegularidad(x);
        cout << "Introduzca la fecha de inicio(dd/mm/yyyy): ";
        cin >> aux;
        t.setFechaInicio(aux);
        cout << "Introduzca el numero de dias que se debe medicar: ";
        cin >> aux;
        x=stoi(aux);
        t.setDuracion(x);
        cout << "Introduzca alguna nota adicional: ";
        cin.ignore();
        getline(cin,aux);
        t.setNotas(aux);
        p.addTratamiento(t);
        break;
      case 3:
        cout << "Introduzca el numero de tratamiento a eliminar: ";
        cin >> aux;
        x=stoi(aux);
        p.eraseTratamiento(x);
        ctrl=false;
        break;
      case 4:
        ctrl=false;
        break;
    }
  }
}
bool Menu::loadPacientes()
{
  bool ctrl=true;
  int x;
  ifstream f("pacientes");
  pacientes_.clear();
  if(f.is_open())
  {
    Paciente p("AA","BB",0);
    string aux;
    while(getline(f, aux, ' '))
    {
      p.setNombre(aux);
      getline(f, aux, ',');
      p.setApellidos(aux);
      getline(f, aux, ',');
      ctrl=p.setFechaNacimiento(aux);
      getline(f, aux, ',');
      p.setSeguroSalud(aux);
      getline(f, aux, ',');
      x=stoi(aux);
      ctrl=ctrl&&p.setDireccionPostal(x);
      getline(f, aux, ',' );
      x=stoi(aux);
      ctrl=ctrl&&p.setTelefono(x);
      getline(f, aux, '\n');
      x=stoi(aux);
      p.setIdHistorialMedico(x);

      pacientes_.push_back(p);

    }
    f.close();
    return true;
  }
  else
    return false;
}
bool Menu::savePacientes()
{
  ofstream f("pacientes");
  for(list<Paciente>::iterator it = pacientes_.begin(); it != pacientes_.end(); ++it)
  {
    f << it->getNombre() << " " << it->getApellidos() << "," << it->getFechaNacimiento() << "," << it->getSeguroSalud() << "," << it->getDireccionPostal() << "," << it->getTelefono() << "," << it->getIdHistorialMedico() << "\n";
  }
  f.close();
}
bool Menu::erasePaciente(const int opcion)
{
  int i=1;
  if(loadPacientes())
  {
    for(list<Paciente>::iterator it=pacientes_.begin();it!=pacientes_.end();++it)
    {
      if(i=opcion)
      {
        pacientes_.erase(it);
        savePacientes();
        return true;
      }
    }
  }
  return false;
}
bool Menu::Add_Paciente()
{
  Paciente p("XX","YY",0);
  int x;
  bool ctrl=true;
  string aux, aux2;
  cout << "Introduzca el primer nombre del paciente: ";
  cin >> aux;
  p.setNombre(aux);
  cout << "Primer apellido: ";
  cin >> aux;
  cout << "Segundo apellido: ";
  cin >> aux2;
  p.setApellidos(aux + " " + aux2);
  cout << "Fecha de nacimiento(dd/mm/yyyy): ";
  cin >> aux;
  ctrl=ctrl&&p.setFechaNacimiento(aux);
  if(!ctrl)
  {
    cout << "Error al introducir la fecha de nacimiento." << endl;
    return false;
  }
  cout << "Seguro de salud: ";
  cin >> aux;
  p.setSeguroSalud(aux);
  cout << "Dirección postal: ";
  cin >> aux;
  x=stoi(aux);
  ctrl=ctrl&&p.setDireccionPostal(x);
  if(!ctrl)
  {
    cout << "Error al introducir la dirección postal." << endl;
    return false;
  }
  cout << "Teléfono móvil: ";
  cin >> aux;
  x=stoi(aux);
  ctrl=ctrl&&p.setTelefono(x);
  if(!ctrl)
  {
    cout << "Error al introducir el teléfono." << endl;
    return false;
  }
  if(!loadPacientes() || pacientes_.empty())
  {
    p.setIdHistorialMedico(1);
  }
  else
  {
    list<Paciente>::iterator it= pacientes_.end();
    --it;
    p.setIdHistorialMedico(it->getIdHistorialMedico()+1);
  }
  ifstream g("historiales");
  aux="";
  while(getline(g,aux2,'\n'))
  {
    aux+=aux2+"\n";
  }
  g.close();
  ofstream f("historiales");
  f << aux;
  f << p.getIdHistorialMedico() << "," << getSysFecha() << "\n";
  f.close();
  pacientes_.push_back(p);
  savePacientes();
  cout << "Paciente introducido correctamente." << endl;
}
void Menu::Consultar_Citas_Diarias()
{
  if(loadPacientes())
  {
    if(citas_diarias_.empty())
    {
      list<Cita> c;
      Paciente p("AA","BB",0);
      Cita_dia cd;
      for(list<Paciente>::iterator it = pacientes_.begin(); it != pacientes_.end();++it)
      {
        p=*it;
        p.loadCitas();
        c=p.getCitas();
        for(list<Cita>::iterator it2 =c.begin(); it2!=c.end();++it2)
        {
          if(cmpFecha(it2->getFecha(),getSysFecha())==0)
          {
            cd.nombre_=p.getNombre();
            cd.apellidos_=p.getApellidos();
            cd.hora_=it2->getHora();
            citas_diarias_.push_back(cd);
          }
        }
      }
      citas_diarias_.sort(cmpHora);
      cout << "Citas del día " << getSysFecha() << " :" << endl;
      for(list<Cita_dia>::iterator it3=citas_diarias_.begin();it3 != citas_diarias_.end(); ++it3)
      {
        cout << "Hora: " << it3->hora_ << "\t" << it3->nombre_ << " " << it3->apellidos_ << endl;
      }
    }
  }
  else
    cout << "---------------"
    << endl << "No hay pacientes en la base de datos."
    << endl << "---------------";
}
void Menu::menu_principal()
{
  cout << "\t-----------"
  << endl << "1.\tMostrar citas del día."
  << endl << "2.\tMostrar lista de pacientes."
  << endl << "3.\tBuscar un paciente."
  << endl << "4.\tAñadir un paciente."
  << endl << "5.\tSalir."
  << endl << "\t-----------"
  << endl;
}
void Menu::menu_paciente()
{
  cout << "\t-----------"
  << endl << "1.\tConsultar datos personales."
  << endl << "2.\tConsultar citas."
  << endl << "3.\tConsultar tratamientos."
  << endl << "4.\tConsultar historial médico."
  << endl << "5.\tAtras."
  << endl << "\t-----------"
  << endl;
}
void Menu::menu_mod_paciente()
{
  cout << "\t-----------"
  << endl << "1.\tCambiar Teléfono móvil."
  << endl << "2.\tCambiar Dirección postal."
  << endl << "3.\tCambiar Seguro de salud."
  << endl << "4.\tEliminar paciente."
  << endl << "5.\tAtras."
  << endl << "\t-----------"
  << endl;
}
void Menu::menu_mod_cita()
{
  cout << "\t-----------"
  << endl << "Elija la opcion que desea: "
  << endl << "1.\tModificar cita."
  << endl << "2.\tAñadir cita."
  << endl << "3.\tEliminar cita."
  << endl << "4.\tAtras."
  << endl << "\t-----------"
  << endl;
}
void Menu::menu_mod_tratamiento()
{
  cout << "\t-----------"
  << endl << "Elija la opcion que desea: "
  << endl << "1.\tModificar tratamiento."
  << endl << "2.\tAñadir tratamiento."
  << endl << "3.\tEliminar tratamiento."
  << endl << "4.\tAtras."
  << endl << "\t-----------"
  << endl;
}
