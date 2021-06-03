#ifndef CONTENEDORA_H
#define CONTENEDORA_H
#include <iostream>
#include "Habitacion.h"
using namespace std;
class Contenedora{
public:
	Contenedora();
	~Contenedora();
	int Habitaciones_disponibles();
	int Habitaciones_mantenimiento();
	int Habitaciones_ocupadas();
	bool Insertar(Cliente *h,int id,Informacion *info);
	bool Liberar_habitacion(string ced);
	int Personas_adultas();
	int Ninos_totales();
	float Dinero_recaudado();
	float Clientes_todo_incluido();
	float Clientes_sin_todo_incluido();
	string toString();
private:
	Habitacion *matriz[5][10];
	int fila;
	int columna;
};
#endif
