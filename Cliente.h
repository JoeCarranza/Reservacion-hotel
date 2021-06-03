#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <sstream>
using namespace std;
class Cliente{
public:
	Cliente();
	Cliente(string nombre_cliente, string numero_identificacion,string forma_pago,float numero_telefono,string numero_cuenta,int edad,int hora);
	~Cliente();
	void setNombre_cliente(string nombre_cliente);
	string getNombre_cliente();
	void setNumero_identificacion(string numero_identificacion);
	string getNumero_identificacion();
	void setForma_pago(string forma_pago);
	string getForma_pago();
	void setNumero_telefono(float numero_telefono);
	float getNumero_telefono();
	void setNumero_cuenta(string numero_cuenta);
	string getNumero_cuenta();
	void setEdad(int edad);
	int getEdad();
	void setHora(int hora);
	int getHora();
	string toString();
private:
	string nombre_cliente;
	string numero_identificacion;
	string forma_pago;
	float numero_telefono;
	string numero_cuenta;
	int edad;
	int hora;
};
#endif
