#ifndef _HISTORIAL_MEDICO_H_
#define _HISTORIAL_MEDICO_H_

#include "linea_medico.h"
#include <string>
#include <list>

using namespace std;

class Historial{

	private:

		int id_Historial_;
		string fecha_alta_;
		list <Linea> Linea_Historial_;


	public: 

		inline Historial(int id_Historial, string fecha_alta, list <Linea> Linea_Historial){id_Historial_=id_Historial; fecha_alta_=fecha_alta; Linea_Historial_=Linea_Historial;}
		inline int getIdHistorialMedico() const {return id_Historial_;};
		inline string getFechaAlta() const {return string fecha_alta_;};
		inline list <Linea_Historial_> getLinea() const {return Linea_Historial_;};
		inline void setIdHistorialMedico(int id_Historial) {id_Historial_=id_Historial;};
		bool setFechaAlta(string fecha_alta);
		bool addlinea(string linea);
		bool LoadLinea(string fichero);



};



#endif