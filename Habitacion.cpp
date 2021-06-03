#include "Cliente.h"
#include "Informacion.h"
#include "Habitacion.h"
using namespace std;

Habitacion::Habitacion(){
	identificador=0;
	estado='L';
	ocupacion=0;
}
Habitacion::Habitacion(int identificador, char estado, int ocupacion, Cliente *c, Informacion *i){
	this->identificador=identificador;
	this->estado=estado;
	this->ocupacion=ocupacion;
	this->c=c;
	this->i=i;
}
Habitacion::~Habitacion(){
	
}
void Habitacion::setIdentificador(int identificador){
	this->identificador=identificador;
}
int Habitacion::getIdentificador(){
	return identificador;
}
void Habitacion::setEstado(char estado){
	this->estado=estado;
}
char Habitacion::getEstado(){
	return estado;
}
void Habitacion::setOcupacion(int ocupacion){
	this->ocupacion=ocupacion;
}
int Habitacion::getOcupacion(){
	return ocupacion;
}
void Habitacion::setCliente(Cliente *c){
	this->c=c;
}
Cliente* Habitacion::getCliente(){
	return c;
}
void Habitacion::setInformacion(Informacion *i){
	this->i=i;
}
Informacion* Habitacion::getInformacion(){
	return i;
}
void Habitacion::Insertar_Cliente(Cliente *c){

}
string Habitacion::toString(){//por si lo llegaramos a ocupar
	stringstream s;
	
	s<<"identificador de la habitacion: "<<identificador<<endl;
	s<<"Estado de la habitacion: "<<estado<<endl;
	s<<"Ocupacion de la habitacion: "<<ocupacion<<endl;
	if(c!=nullptr){
		s<<endl;
		s<<c->toString();
	}else if(c==nullptr){
		s<<"No exite un cliente en esta habitacion"<<endl;
	}if(c!=nullptr){
		s<<endl;
		s<<i->toString();
	}else if(i==nullptr){
		s<<endl;
		s<<"No hay informacion"<<endl;
	}
	return s.str();
}
