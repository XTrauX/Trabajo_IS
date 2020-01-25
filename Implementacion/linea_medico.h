
#ifndef _LINEA_H_
#define _LINEA_H_

//bloques de includes

#include <string>
using namespace std;
class Linea{

	private:
		int num_linea_;
		string comentario_, fecha_;

	public:
		inline Linea(int num_linea,string comentario="", string fecha="99/99/9999") {num_linea_=num_linea; comentario_=comentario; fecha_=fecha;};
		inline int getNumeroLinea() const {return num_linea_;};
		inline string getComentario() const {return comentario_;};
		inline string getFecha() const {return fecha_;};
		inline void setNumeroLinea(int num_linea){num_linea_=num_linea;}; //pensar para hablarlo con MasterScrum
		inline void setComentario(string comentario) {comentario_=comentario;};
		inline void setFecha(string fecha) {fecha_=fecha;};


};

#endif
