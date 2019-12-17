#include "paciente.h"
#include "fecha.h"
#include <fstream>

using namespace std;

Paciente::Paciente(string nombre, string apellidos, int idHistorialMedico, string fechaNacimiento, string seguroSalud, int direccionPostal, int telefono){
  nombre_ = nombre;
  apellidos_ = apellidos;
  idHistorialMedico_ = idHistorialMedico;
  if(setFechaNacimiento(fechaNacimiento)){
  }
  else{
    fechaNacimiento_ = "";
  }
  seguroSalud_ = seguroSalud;
  if(setDireccionPostal(direccionPostal)){
  }
  else{
    direccionPostal_ = 0;
  }
  if(setTelefono(telefono)){
  }
  else{
    telefono_ = 0;
  }
}

bool Paciente::setDireccionPostal(int direccionPostal){
  if((direccionPostal > 9999) && (direccionPostal < 100000)){
    direccionPostal_ = direccionPostal;
    return true;
  }
  else{
    return false;
  }
}

bool Paciente::setFechaNacimiento(string fechaNacimiento){
  if(cmpFecha(fechaNacimiento , getSysFecha()) == -1){
    fechaNacimiento_ = fechaNacimiento;
    return true;
  }
  else{
    return false;
  }
}

bool Paciente::setTelefono(int telefono){
  if((telefono > 599999999) && (telefono < 1000000000)){
    telefono_ = telefono;
    return true;
  }
  else{
    return false;
  }
}

void Paciente::addCita(Cita cita){
  if(loadCitas()){
    cita.setIdCita((citas_.size() + 1));
  }
  else{
    cita.setIdCita(1);
  }
  citas_.push_back(cita);
  saveCitas();
}

void Paciente::addTratamiento(Tratamiento tratamiento){
  if(loadTratamientos()){
    tratamiento.setIdTratamiento((tratamientos_.size() + 1));
  }
  else{
    tratamiento.setIdTratamiento(1);
  }
  tratamientos_.push_back(tratamiento);
  saveTratamientos();
}

bool Paciente::modifyCita(Cita cita){
  if(loadCitas()){
    int n = cita.getIdCita();
    if((n > 0) && (n <= (int)citas_.size())){
      list<Cita>::iterator it = citas_.begin();
      while(n!=1){
        it++;
        n--;
      }
      it->setFecha(cita.getFecha());
      it->setHora(cita.getHora());
      it->setDuracion(cita.getDuracion());
      saveCitas();
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

bool Paciente::modifyTratamiento(Tratamiento tratamiento){
  if(loadTratamientos()){
    int n = tratamiento.getIdTratamiento();
    if((n > 0) && (n <= (int)tratamientos_.size())){
      list<Tratamiento>::iterator it = tratamientos_.begin();
      while(n!=1){
        it++;
        n--;
      }
      it->setMedicamento(tratamiento.getMedicamento());
      it->setConcentracion(tratamiento.getConcentracion());
      it->setRegularidad(tratamiento.getRegularidad());
      it->setFechaInicio(tratamiento.getFechaInicio());
      it->setDuracion(tratamiento.getDuracion());
      it->setNotas(tratamiento.getNotas());
      saveTratamientos();
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

bool Paciente::eraseCita(int n){
  if(loadCitas()){
      if((n > 0) && (n <= (int)citas_.size())){
        for(list<Cita>::iterator it = citas_.begin() ; it != citas_.end() ; ++it){
          citas_.erase(it);
        }
        saveCitas();
        return true;
      }
      else{
        return false;
      }
  }
  else{
    return false;
  }
}

bool Paciente::eraseTratamiento(int n){
  if(loadTratamientos()){
      if((n > 0) && (n <= (int)tratamientos_.size())){
        for(list<Tratamiento>::iterator it = tratamientos_.begin() ; it != tratamientos_.end() ; ++it){
          tratamientos_.erase(it);
        }
        saveTratamientos();
        return true;
      }
      else{
        return false;
      }
  }
  else{
    return false;
  }
}

bool Paciente::loadCitas(){
  string doc = "citas/" + nombre_ + " " + apellidos_ + ".txt";
  ifstream f(doc);
  citas_.clear();
  if(f.is_open()){
    Cita a;
    string aux;
    while(getline(f, aux, ',')){
      a.setIdCita(stoi(aux));
      getline(f, aux, ',');
      a.setFecha(aux);
      getline(f, aux, ',');
      a.setHora(aux);
      getline(f, aux, '\n');
      a.setDuracion(stoi(aux));

      citas_.push_back(a);
    }
    f.close();
    return true;
  }
  else{
    return false;
  }
}

bool Paciente::loadTratamientos(){
  string doc = "tratamientos/" + nombre_ + " " + apellidos_ + ".txt";
  ifstream f(doc);
  tratamientos_.clear();
  if(f.is_open()){
    Tratamiento a;
    string aux;
    while(getline(f, aux, ',')){
      a.setIdTratamiento(stoi(aux));
      getline(f, aux, ',');
      a.setMedicamento(aux);
      getline(f, aux, ',');
      a.setConcentracion(stof(aux));
      getline(f, aux, ',');
      a.setRegularidad(stoi(aux));
      getline(f, aux, ',');
      a.setFechaInicio(aux);
      getline(f, aux, ',');
      a.setDuracion(stoi(aux));
      getline(f, aux, '\n');
      a.setNotas(aux);

      tratamientos_.push_back(a);
    }
    f.close();
    return true;
  }
  else{
    return false;
  }
}

void Paciente::saveCitas(){
  string doc = "citas/" + nombre_ + " " + apellidos_ + ".txt";
  ofstream f(doc);
  int n = 1;
  for(list<Cita>::iterator it = citas_.begin() ; it != citas_.end() ; ++it){
    it->setIdCita(n);
    f << it->getIdCita() << "," << it->getFecha() << "," << it->getHora() << "," << it->getDuracion() << "\n";
    n++;
  }
  f.close();
}

void Paciente::saveTratamientos(){
  string doc = "tratamientos/" + nombre_ + " " + apellidos_ + ".txt";
  ofstream f(doc);
  int n = 1;
  for(list<Tratamiento>::iterator it = tratamientos_.begin() ; it != tratamientos_.end() ; ++it){
    it->setIdTratamiento(n);
    f << it->getIdTratamiento() << "," << it->getMedicamento() << "," << it->getConcentracion() << "," << it->getRegularidad() << "," << it->getFechaInicio() << "," << it->getDuracion() << "," << it->getNotas() << "\n";
    n++;
  }
  f.close();
}
