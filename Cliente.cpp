#include "Cliente.h"
using namespace std;

Cliente::Cliente(){
	nombre_cliente= " ";
	numero_identificacion=" ";
	forma_pago=" ";
	numero_telefono=0.0;
	numero_cuenta=" ";
	edad=0;
	hora=0;
}
Cliente::Cliente(string nombre_cliente, string numero_identificacion,string forma_pago,float numero_telefono,string numero_cuenta,int edad,int hora){
	this->nombre_cliente=nombre_cliente;
	this->numero_identificacion=numero_identificacion;
	this->forma_pago=forma_pago;
	this->numero_telefono=numero_telefono;
	this->numero_cuenta=numero_cuenta;
	this->edad=edad;
	this->hora=hora;
}
Cliente::~Cliente(){
	
}
void Cliente::setNombre_cliente(string nombre_cliente){
	this->nombre_cliente=nombre_cliente;
}
string Cliente::getNombre_cliente(){
	return nombre_cliente;
}
void Cliente::setNumero_identificacion(string numero_identificacion){
	this->numero_identificacion=numero_identificacion;
}
string Cliente::getNumero_identificacion(){
	return numero_identificacion;
}
void Cliente::setForma_pago(string forma_pago){
	this->forma_pago=forma_pago;
}
string Cliente::getForma_pago(){
	return forma_pago;
}
void Cliente::setNumero_telefono(float numero_telefono){
	this->numero_telefono=numero_telefono;
}
float Cliente::getNumero_telefono(){
	return numero_telefono;
}
void Cliente::setNumero_cuenta(string numero_cuenta){
	this->numero_cuenta=numero_cuenta;
}
string Cliente::getNumero_cuenta(){
	return numero_cuenta;
}
void Cliente::setEdad(int edad){
	this->edad=edad;
}
int Cliente::getEdad(){
	return edad;
}
void Cliente::setHora(int hora){
	this->hora=hora;
}
int Cliente::getHora(){
	return hora;
}
string Cliente::toString(){//por si lo llegaramos a ocupar
	stringstream s;
	s<<"Nombre del cliente: "<<nombre_cliente<<endl;
	s<<"Identificacion del cliente: "<<numero_identificacion<<endl;
	s<<"Forma de pago: "<<forma_pago<<endl;
	s<<"Numero de telefono: "<<numero_telefono<<endl;
	s<<"Edad: "<<edad<<endl;
	return s.str();
}
