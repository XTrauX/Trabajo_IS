#ifndef _PACIENTE_H_
#define _PACIENTE_H_

//Bloque de includes
#include <string>
#include <list>
#include "tratamiento.h"
#include "cita.h"
#include "historial_medico.h"

//Declaración de la clase paciente
class Paciente{
private:
  string apellidos_, nombre_, fechaNacimiento_, seguroSalud_;
  int direccionPostal_, telefono_, idHistorialMedico_;
  Historial historial_;

public:

  list<Cita> citas_;
  list<Tratamiento> tratamientos_;
  Paciente(string nombre, string apellidos, int idHistorialMedico, string fechaNacimiento = "", string seguroSalud = "", int direccionPostal = 0, int telefono = 0);
  inline string getApellidos() const {return apellidos_;};
  inline string getNombre() const {return nombre_;};
  inline int getDireccionPostal() const {return direccionPostal_;};
  inline string getFechaNacimiento() const {return fechaNacimiento_;};
  inline int getTelefono() const {return telefono_;};
  inline string getSeguroSalud() const {return seguroSalud_;};
  inline int getIdHistorialMedico() const {return idHistorialMedico_;};
  inline list<Cita> getCitas() const {return citas_;};
  inline list<Tratamiento> getTratamientos() const {return tratamientos_;};
  inline Historial getHistorial() const {return historial_;};
  inline void setApellidos(string apellidos) {apellidos_ = apellidos;};
  inline void setNombre(string nombre) {nombre_ = nombre;};
  inline void setIdHistorialMedico(const int &id) {idHistorialMedico_=id;};
  bool setDireccionPostal(int direccionPostal);
  bool setFechaNacimiento(string fechaNacimiento);
  bool setTelefono(int telefono);
  inline void setSeguroSalud(string seguroSalud) {seguroSalud_ = seguroSalud;};
  void addCita(Cita cita);
  void addTratamiento(Tratamiento tratamiento);
  bool modifyCita(Cita cita);
  bool modifyTratamiento(Tratamiento tratamiento);
  bool eraseCita(int n);
  bool eraseTratamiento(int n);
  bool loadCitas();
  bool loadTratamientos();
  bool loadHistorial();
  void saveCitas();
  void saveTratamientos();
};

#endif
