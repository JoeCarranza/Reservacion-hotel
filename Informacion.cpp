#include "Informacion.h"
using namespace std;

Informacion::Informacion(){
	num_adultos=0;
	num_ninos=0;
	num_dias=0;
	estancia=false;
}
Informacion::Informacion(int num_adultos,int num_ninos,int num_dias,bool estancia){
	this->num_adultos=num_adultos;
	this->num_ninos=num_ninos;
	this->num_dias=num_dias;
	this->estancia=estancia;
}
Informacion::~Informacion(){
	
}
void Informacion::setNum_adultos(int num_adultos){
	this->num_adultos=num_adultos;
}
int Informacion::getNum_adultos(){
	return num_adultos;
}
void Informacion::setNum_ninos(int num_ninos){
	this->num_ninos=num_dias;
}
int Informacion::getNum_ninos(){
	return num_ninos;
}
void Informacion::setNum_dias(int num_dias){
	this->num_dias=num_dias;
}
int Informacion::getNum_dias(){
	return num_dias;
}
void Informacion::setEstancia(bool estancia){
	this->estancia=estancia;
}
bool Informacion::getEstancia(){
	return estancia;
}
string Informacion::toString(){//por si lo ocupamos para mostrar algo de informacion
	stringstream s;
	s<<"La cantidad de adultos es: "<<num_adultos<<endl;
	s<<"La cantidad de ninos es: "<<num_ninos<<endl;
	s<<"La estancia es: "<<estancia<<endl;
	s<<"La cantidad de dias: "<<num_dias<<endl;
	return s.str();
}
