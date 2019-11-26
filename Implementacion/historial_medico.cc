#include "historial_medico.h"
#include "linea_medico.h"
#include "fecha.h"

#include <list>
#include <string>
#include <ctime>

bool Historial::setFechaAlta(string fecha_alta){

	fecha_alta_=getSysFecha();
	return true;
}

bool Historial::addLinea(Linea linea, string nombre, string apellidos){

	string fichero= nombre+apellidos + ".txt";
	list <Linea> ::iterator i;
	bool anadir true;
	for(i=Linea.begin(); i!=Linea.end(); ++i){


		if(linea.num_linea_==(*i).getNumeroLinea()){

			anadir false;
		}

			
	}

	if(anadir) Linea.push_back(linea);

	ifstream entrada(fichero);

	if(entrada.is_open()) return false;
	else{
		ofstream entrada(fichero);
	    entrada.close();
	    return true;
	}


}

bool Historial::LoadLinea(string fichero){

	//antes de nada limpiamos cita
	Linea a(0,"XXXX","XXXX");
	Linea_Historial_.clear();
	//comprobamos si existe el fichero
	if(entrada.is_open()) return false;
	//abrimos el fichero en modo lectura
	ifstream entrada(fichero);
	//declaramos una variable auxiliar tipo string para ir guardando los datos
	string aux;
	int x; //para guardar los tipo int
	//recorremos el fichero leyendo
	while(getline(entrada,aux,',')){
	x=stoi(aux);
	a.setNumeroLista(x);
	getline(entrada,aux,'\n')
	a.setFechaAlta(aux);

	Linea_Historial_.push_back(a);

	}

	entrada.close();
	return true;
}