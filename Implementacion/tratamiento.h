#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>

using namespace std;

class Tratamiento{

private:

  int Id_Tratamiento_Medico_;
  string Medicamento_;
  float Concentracion_;
  int Regularidad_;
  string Fecha_de_Inicio_;
  int Duracion_;
  string Notas_;

public:

  //getters
  inline int getIdTratamiento() const {return Id_Tratamiento_Medico_;};
  inline string getMedicamento() const {return Medicamento_;};
  inline float getConcentracion() const {return Concentracion_;};
  inline int getRegularidad() const {return Regularidad_;};
  inline string getFechaInicio() const {return Fecha_de_Inicio_;};
  inline int getDuracion() const {return Duracion_;};
  inline string getNotas() const {return Notas_;};
  //setters
  void setIdTratamiento(int const Id_Tratamiento_Medico) {Id_Tratamiento_Medico_=Id_Tratamiento_Medico;};
  void setMedicamento(string const Medicamento) {Medicamento_=Medicamento;};
  void setConcentracion(float const Concentracion) {Concentracion_=Concentracion;};
  void setRegularidad(int const Regularidad) {Regularidad_=Regularidad;};
  void setFechaInicio(string const Fecha_de_Inicio) {Fecha_de_Inicio_=Fecha_de_Inicio;};
  void setDuracion(int const Duracion) {Duracion_=Duracion;};
  void setNotas(string const Notas) {Notas_=Notas;};

};

#endif
