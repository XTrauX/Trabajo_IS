#ifndef _CITA_H_
#define _CITA_H_

#include <string>

using namespace std;

class Cita{

	private:
		int Id_Cita_,Duracion_;
		string fecha_,hora_;

	public:
		inline Cita(int IdCita, int Duracion=0, string fecha="", string hora="") {Id_Cita_=IdCita; Duracion_=Duracion; fecha_=fecha; hora_=hora;};
		inline int getIdCita() const {return Id_Cita_;};
		inline int getDuracion() const {return Duracion_;};
		inline string getFecha() const {return fecha_;};
		inline string getHora() const {return hora_;};
		inline void setIdCita(int IdCita){Id_Cita_=IdCita;};
		inline void setFecha(string fecha){fecha_=fecha;};
		inline void setHora(string hora){hora_=hora;};
		inline void setDuracion(int Duracion){Duracion_=Duracion;};
};
#endif
