#ifndef _CITA_H_
#define _CITA_H_

#include <string>

class cita{

	private:
		int Id_Cita_, Duracion_;
		string fecha_, hora_;

	public:

		inline cita(int Id_Cita, int Duracion, string fecha, string hora) {Id_Cita_=Id_Cita; Duracion_=Duracion; fecha_=fecha; hora_=hora;}
		inline int getIdCita() const {return Id_Cita_;};
		inline int getDuracion() const {return Duracion_;};
		inline string getFecha() const {return fecha_;};
		inline string getHora() const {return hora_;};
		inline void setIdCita(Id_Cita){Id_Cita_=Id_Cita;}
		inline void setFecha(string fecha){fecha_=fecha;}
		inline void setHora(string hora){hora_=hora;}
		inline void setDuracion(int Duracion){Duracion_=Duracion;}
		

};
#endif