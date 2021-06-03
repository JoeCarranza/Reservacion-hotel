#include "Contenedora.h "
#include "Habitacion.h"
using namespace std;
static int contador=1;
Contenedora::Contenedora(){
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
		matriz[i][j]=new Habitacion();
		matriz[i][j]->setIdentificador(contador);
		contador++;
		}
	}
	matriz[3][4]->setEstado('M');
	matriz[1][7]->setEstado('M');
	matriz[4][2]->setEstado('M');
}

Contenedora::~Contenedora(){
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			delete matriz[i][j];	
		}
	}
}
int Contenedora::Habitaciones_disponibles(){
	int contador=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='L'){
				contador++;
			}
		}
	}
	return contador;
}
int Contenedora::Habitaciones_mantenimiento(){
	int contador=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='M'){
				contador++;
			}
		}
	}
	return contador;
	
}
int Contenedora::Habitaciones_ocupadas(){
	int contador=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='O'){
				contador++;
			}
		}
	}
	return contador;
}
bool Contenedora::Insertar(Cliente *c,int id,Informacion *info){
	bool resultado=false;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getIdentificador()==id){
				if(matriz[i][j]->getEstado()!='O'&& matriz[i][j]->getEstado()!='M'){
					matriz[i][j]->setCliente(c);
					matriz[i][j]->setInformacion(info);
					matriz[i][j]->setEstado('O');
					return resultado=true;
				}
			}
		}
	}
	return resultado;
}
bool Contenedora::Liberar_habitacion(string ced){
	bool resultado=false;
	for(int i=0;i<fila;i++){
		for(int j=0;j<columna;j++){
			if(matriz[i][j]->getEstado()=='O'){
				if(matriz[i][j]->getCliente()->getNumero_identificacion()==ced){
					delete matriz[i][j];
					matriz[i][j]=new Habitacion;
					matriz[i][j]->setEstado('M');
					return true;
				}
			}
		}
    }
	return resultado;
}
int Contenedora::Personas_adultas(){
	int contador=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='O'){
				contador+=matriz[i][j]->getInformacion()->getNum_adultos();
			}
		}
	}
	return contador;
}
int Contenedora::Ninos_totales(){
	int contador=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='O'){
				contador+=matriz[i][j]->getInformacion()->getNum_ninos();
			}
		}
	}
	return contador;
}
float Contenedora::Dinero_recaudado(){
	float total=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='O'){
				if(matriz[i][j]->getOcupacion()==1){
					total+=150*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==2){
					total+=250*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==3){
					total+=350*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==4){
					total+=400*matriz[i][j]->getInformacion()->getNum_dias();
				}
				if(matriz[i][j]->getCliente()->getHora()>=18){
					if(matriz[i][j]->getInformacion()->getEstancia()==false){
						if(matriz[i][j]->getOcupacion()==1){
							total+=150*0.25 * matriz[i][j]->getInformacion()->getNum_dias();
						}else if(matriz[i][j]->getOcupacion()==2){
							total+=250*0.20 * matriz[i][j]->getInformacion()->getNum_dias();
						}else if(matriz[i][j]->getOcupacion()==3){
							total+=350*0.15 * matriz[i][j]->getInformacion()->getNum_dias();
						}else if(matriz[i][j]->getOcupacion()==4){
							total+=400*0.10 * matriz[i][j]->getInformacion()->getNum_dias();
						}
					}
				}
				if(matriz[i][j]->getInformacion()->getEstancia()==true){
					total+=300 * matriz[i][j]->getInformacion()->getNum_adultos() * matriz[i][j]->getInformacion()->getNum_dias();
					total+=200 * matriz[i][j]->getInformacion()->getNum_ninos() * matriz[i][j]->getInformacion()->getNum_dias();
				}
			}
		}
	}
	return total;
}
float Contenedora::Clientes_todo_incluido(){
	float total=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='O'){
				if(matriz[i][j]->getOcupacion()==1){
					total+=150*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==2){
					total+=250*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==3){
					total+=350*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==4){
					total+=400*matriz[i][j]->getInformacion()->getNum_dias();
				}
				if(matriz[i][j]->getInformacion()->getEstancia()==true){
					total+=300 * matriz[i][j]->getInformacion()->getNum_adultos() * matriz[i][j]->getInformacion()->getNum_dias();
					total+=200 * matriz[i][j]->getInformacion()->getNum_ninos() * matriz[i][j]->getInformacion()->getNum_dias();
				}
			}
		}
	}
	return total;
}
float Contenedora::Clientes_sin_todo_incluido(){
	float total=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
			if(matriz[i][j]->getEstado()=='O'){
				if(matriz[i][j]->getOcupacion()==1){
					total+=150*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==2){
					total+=250*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==3){
					total+=350*matriz[i][j]->getInformacion()->getNum_dias();
				}else if(matriz[i][j]->getOcupacion()==4){
					total+=400*matriz[i][j]->getInformacion()->getNum_dias();
				}
				if(matriz[i][j]->getCliente()->getHora()>=18){
					if(matriz[i][j]->getInformacion()->getEstancia()==false){
						if(matriz[i][j]->getOcupacion()==1){
							total+=150*0.25 * matriz[i][j]->getInformacion()->getNum_dias();
						}else if(matriz[i][j]->getOcupacion()==2){
							total+=250*0.20 * matriz[i][j]->getInformacion()->getNum_dias();
						}else if(matriz[i][j]->getOcupacion()==3){
							total+=350*0.15 * matriz[i][j]->getInformacion()->getNum_dias();
						}else if(matriz[i][j]->getOcupacion()==4){
							total+=400*0.10 * matriz[i][j]->getInformacion()->getNum_dias();
						}
					}
				}
			}
		}
	}
	return total;
}
string Contenedora::toString(){
	stringstream s;
	for(int i=0;i<5;i++){
		for(int j=0;j<10;j++){
		s<<matriz[i][j]->getEstado()<<" ";
		}
		s<<endl;
	}
	return s.str();
}
