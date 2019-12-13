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

bool Historial::addLinea(Linea linea, string nombre, string apellidos){

	string fichero= nombre+apellidos + ".txt";
	
	Linea_Historial_.push_back(linea);

	

	if(ifstream (fichero)) return false;
	else{
		ofstream (fichero);
	    fichero.close();
	    return true;
	}


}

bool Historial::LoadLinea(string fichero){

	//antes de nada limpiamos cita
	Linea a(0,"XXXX","XXXX");
	Linea_Historial_.clear();
	//comprobamos si existe el fichero
	if(ifstream(fichero)) return false;

	ifstream entrada (fichero);
	//declaramos una variable auxiliar tipo string para ir guardando los datos
	string aux;
	int x; //para guardar los tipo int
	//recorremos el fichero leyendo
	while(getline(entrada,aux,',')){
	x=stoi(aux);
	a.setNumeroLista(x);
	getline(entrada,aux,'\n');
	a.setFecha(aux);

	Linea_Historial_.push_back(a);

	}

	entrada.close();
	return true;
}
