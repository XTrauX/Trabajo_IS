#ifndef _HISTORIAL_MEDICO_H_
#define _HISTORIAL_MEDICO_H_

#include "linea_medico.h"
#include <list>

using namespace std;

class Historial{

	private:

		int id_Historial_;
		string fecha_alta_;
		list <Linea> Linea_Historial_;


	public:

		inline Historial(int id_Historial=0, string fecha_alta=""){id_Historial_=id_Historial; fecha_alta_=fecha_alta;};
		inline void fsetFechaAlta(string fecha){fecha_alta_=fecha;};
		inline int getIdHistorialMedico() const {return id_Historial_;};
		inline string getFechaAlta() const {return fecha_alta_;};
		inline list <Linea> getLinea() const {return Linea_Historial_;};
		inline void setIdHistorialMedico(int id_Historial) {id_Historial_=id_Historial;};
		bool setFechaAlta();
		void addLinea(Linea linea);
		bool LoadLinea();
		void SaveLinea();
};



#endif
