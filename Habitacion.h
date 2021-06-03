#ifndef HABITACION_H
#define HABITACION_H
#include <iostream>
#include "Cliente.h"
#include "Informacion.h"
#include <sstream>
using namespace std;
class Habitacion{
public:
	Habitacion();
	Habitacion(int identificador, char estado, int ocupacion, Cliente *c, Informacion *i);
	~Habitacion();
	void setIdentificador(int identificador);
	int getIdentificador();
	void setEstado(char estado);
	char getEstado();
	void setOcupacion(int ocupacion);
	int getOcupacion();
	void setCliente(Cliente *c);
	Cliente* getCliente();
	void setInformacion(Informacion *i);
	Informacion* getInformacion();
	void Insertar_Cliente(Cliente *c);
	string toString();
private:
	int identificador;
	char estado;
	int ocupacion;
	Cliente *c;
	Informacion *i;
	int contador;
};
#endif
