#include<iostream>
#include "Contenedora.h"
#include "windows.h"
using namespace std;

int main () {
	int opcion=0;
	string nombre=" "; 
	string numero_identificacion;
	string forma_pago=" ";
	float numero_telefono=0;
	string numero_cuenta=" ";
	int edad=0;
	int hora=0;
	int num_adultos=0;
	int num_ninos=0;
	int num_dias=0;
	int identificador=0; 
	int ocupacion;
	string variable=" ";
	bool estancia=false;
	string id_cliente=" ";
	Contenedora *c=new Contenedora();
	do{
		system("cls");
		cout<<"------------------Bienvenido------------------- \n"
			<<"*************************************************\n"
			<<"------------------Hotel zzplus-----------------\n"
			<<"Digite una de las siguiente opciones: \n"
			<<"1-Ver cuantas habitaciones hay disponibles. \n"
			<<"2-Ver cuantas habitaciones estan en mantenimiento. \n"
			<<"3-Ver cuantas habitaciones estan en mantenimiento. \n"
			<<"4- Registrar habitacion. \n"
			<<"5- Liberar Habitacion. \n"
			<<"6- Ver cuantas personas adultas hay en el hotel. \n"
			<<"7- Ver cuantos niños hay en el hotel. \n"
			<<"8-Saber cuanto dinero recaudo el hotel. \n"
			<<"9-Salir del programa. \n";
		cin>>opcion;
		switch(opcion){
		case 1:
			cout<<"Como puedes ver el hotel cuenta con un total de: "<<c->Habitaciones_disponibles()<<" Habitaciones disponibles"<<endl;
			cout<<c->toString()<<endl;
			system("pause");
			break;
		case 2:
			cout<<"Como puedes ver el hotel cuenta con un total de: "<<c->Habitaciones_mantenimiento()<<" en Habitaciones en mantenimiento"<<endl;
			cout<<c->toString()<<endl;
			system("pause");
			break;
		case 3:
			cout<<"Como puedes ver el hotel cuenta con un total de: "<<c->Habitaciones_ocupadas()<<" Habitaciones ocupadas"<<endl;
			cout<<c->toString()<<endl;
			system("pause");
			break;
		case 4:
			system("cls");
			cout<<"Cuantas personas van a ocupar la habitacion"<<endl;
			cin>>ocupacion;
			if(ocupacion>4){
				cout<<"La ocupacion maxima de la habitacion es de 4 lo sentimos. "<<endl;
				system("pause");
				break;
			}
			system("cls");
			cout<<"Digite la cantidad de adultos que vienen con usted. \n";
			cin>>num_adultos;
			system("cls");
			cout<<"Digite la cantidad de niños que vienen con usted. \n";
			cin>>num_ninos;
			system("cls");
			if(num_adultos+num_ninos!=ocupacion){
				cout<<"La cantidad de personas es diferente a lo que solicito anteriormente \n";
				cout<<"Por favor realice de nuevo el registro para no tener problemas \n";
				system("pause");
				break;
			}else{
				cout<<c->toString()<<endl;
				cout<<"Digite el numero de habitacion que desea. (1-50)\n";
				cin>>identificador;
				if(identificador==0 || identificador>50){
				cout<<"Esta habitacion no existe por favor vuelva a intentarlo."<<endl;
				system("pause");
				break;
				}
				system("cls");
				cout<<"Digite su nombre. (sin apellidos)\n"<<endl;
				cin>>nombre;
				system("cls");
				cout<<"Digite su numero de identificacion.(formato 00000000) \n";
				cin>>numero_identificacion;
				system("cls");
				cout<<"Digite su numero de cuenta. \n";
				cin>>numero_cuenta;
				system("cls");
				cout<<"Digite el metodo de pago que desea realizar. (efectivo o trajeta)\n";
				cin>>forma_pago;
				system("cls");
				cout<<"Digite su numero de telefono. \n";
				cin>>numero_telefono;
				system("cls");
				cout<<"Digite su edad. \n";
				cin>>edad;
				system("cls");
				cout<<"Digite el numero de dias que se va a quedar en el hotel. \n";
				cin>>num_dias;
				system("cls");
				cout<<"Digite la hora de entrada al hotel. (utilizamos el formato de hora militar 0-24/h) \n";
				cin>>hora;
				system("cls");
				cout<<"¿Desea adquirir el servicio todo incluido ? Digite si o no"<<endl;
				cin>>variable;
				if(variable=="si"||variable=="Si"||variable=="SI"){
					estancia=true;
				}
				Cliente *cliente= new Cliente(nombre,numero_identificacion,forma_pago,numero_telefono,numero_cuenta,edad,hora);
				Informacion *info= new Informacion(num_adultos,num_ninos,num_dias,estancia);
				if(c->Insertar(cliente,identificador,info)==true){
					cout<<"Cliente ingresado con exito. Bienvenido!!!"<<endl;
					system("pause");
					break;
				}else{
					cout<<"La habitacion que usted eligio en este momento no esta disponible o esta en mantenimiento "<<endl;
					system("pause");
					break;
				}
			}
		case 5:
			   cout<<"Digite el numero de cedula del cliente"<<endl;
			   cin>>id_cliente;
			   if(c->Liberar_habitacion(id_cliente)==true){
				   cout<<"Habitacion liberada con exito"<<endl;
				   system("pause");
				   break;
			   }else{
				   cout<<"Ocurrio un error y la habitacion no pudo ser liberada"<<endl;
				   system("pause");
				   break;
			   }
		case 6:
			cout<<"La cantidad de personas adultas en el hotel es: "<<c->Personas_adultas()<<endl;
			system("pause");
			break;
		case 7:
			cout<<"La cantidad de niños en el hotel es: "<<c->Ninos_totales()<<endl;
			system("pause");
			break;
		case 8:
			cout<<"El total recaudado por el hotel es de: "<<c->Dinero_recaudado()<<endl;
			cout<<"Dinero total de clientes con todo incluido es de: "<<c->Clientes_todo_incluido()<<endl;
			cout<<"Dinero total de clientes sin todo incluido es de: "<<c->Clientes_sin_todo_incluido()<<endl;
			system("pause");
			break;
		default:
			if(opcion!=9){
				cout<<"Esta opcion no existe, por favor intente de nuevo."<<endl;
				system("pause");	
			}
			break;
		}
	} while(opcion!=9);
	cout<<"Gracias por utilizar el programa.Nos vemos pronto."<<endl;
	
	return 0;
}

