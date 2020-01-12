all : main.x

main.x: menu.o paciente.o fecha.o cita.o historial_medico.o linea_medico.o tratamiento.o
	g++ -Wall -Wpedantic -o main.x main.cc menu.o paciente.o fecha.o cita.o historial_medico.o linea_medico.o tratamiento.o -std=gnu++11

menu.o : menu.cc menu.h paciente.o
	g++ -c menu.cc -std=gnu++11

paciente.o : paciente.cc paciente.h fecha.o cita.o historial_medico.o
	g++ -c paciente.cc -std=gnu++11

fecha.o : fecha.cc fecha.h
	g++ -c fecha.cc -std=gnu++11

cita.o : cita.cc cita.h
	g++ -c cita.cc -std=gnu++11

historial_medico.o : historial_medico.cc historial_medico.h linea_medico.o
	g++ -c historial_medico.cc -std=gnu++11

linea_medico.o : linea_medico.cc linea_medico.h
	g++ -c linea_medico.cc -std=gnu++11

tratamiento.o : tratamiento.cc tratamiento.h
	g++ -c tratamiento.cc -std=gnu++11

clean :
	rm -rf *o main.x
