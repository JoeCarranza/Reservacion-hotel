#ifndef INFORMACION_H
#define INFORMACION_H
#include <iostream>
#include <sstream>
using namespace std;
class Informacion{
public:
	Informacion();
	Informacion(int num_adultos,int num_ninos,int num_dias,bool estancia);
	~Informacion();
	void setNum_adultos(int num_adultos);
	int getNum_adultos();
	void setNum_ninos(int num_ninos);
	int getNum_ninos();
	void setNum_dias(int num_dias);
	int getNum_dias();
	void setEstancia(bool estancia);
	bool getEstancia();
	string toString();
private:
	int num_adultos;
	int num_ninos;
	int num_dias;
	bool estancia;
};
#endif
