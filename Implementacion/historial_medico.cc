#include "historial_medico.h"
#include "linea_medico.h"
#include "fecha.h"

#include <list>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

bool Historial::setFechaAlta(){

	fecha_alta_=getSysFecha();
	return true;
}

void Historial::addLinea(Linea linea){

	if(LoadLinea())
	{
		linea.setNumeroLinea(Linea_Historial_.size()+1);
	}
	else
		linea.setNumeroLinea(1);
	linea.setFecha(getSysFecha());
	Linea_Historial_.push_back(linea);
	SaveLinea();
}

bool Historial::LoadLinea(){

	//antes de nada limpiamos cita
	Linea a(0,"XXXX","XXXX");
	Linea_Historial_.clear();
	string fichero1= "lineas/" + to_string(id_Historial_) + ".txt";
	//comprobamos si existe el fichero
	ifstream entrada (fichero1);
	if(!entrada.is_open()) return false;
	//declaramos una variable auxiliar tipo string para ir guardando los datos
	string aux;
	int x; //para guardar los tipo int
	//recorremos el fichero leyendo
	while(getline(entrada,aux,','))
	{
	x=stoi(aux);
	a.setNumeroLinea(x);
	getline(entrada,aux,',');
	a.setFecha(aux);
	getline(entrada, aux, '\n');
	a.setComentario(aux);

	Linea_Historial_.push_back(a);
	}
	entrada.close();
	return true;
}
void Historial::SaveLinea(){
	string fichero1= "lineas/" + to_string(id_Historial_) + ".txt";
	int num=1;
	ofstream f(fichero1);
	for(list<Linea>::iterator it= Linea_Historial_.begin(); it != Linea_Historial_.end(); ++it)
	{
		f << num << "," << it->getFecha() << "," << it->getComentario() << "\n";
		num++;
	}
}
