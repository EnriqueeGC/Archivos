#include <iostream>
#include <stdio.h>  
#include <string.h> 
using namespace std;
const char *archivo_tarea1 = "archivo.dat";
const char *eliminar_registro = "archivo1.dat";

struct tipo_registro{
	int codigo;
	int telefono;
	char nombre[30];
	char apellido[30];
	char direccion[30];
}Registro;

void ingreso_datos(){
	FILE *archivo = fopen(archivo_tarea1, "ab");
	cout<<"Ingrese el Codigo del Estudiante: ";
	cin>>Registro.codigo;
	cout<<"Ingrese el Nombre del Estudiante: ";
	cin>>Registro.nombre;
	cout<<"Ingrese el Apellido del Estudiante: ";
	cin>>Registro.apellido;
	cout<<"Ingrese la Direccion del Estudiante: ";
	cin>>Registro.direccion;
	cout<<"Ingrese el Telefono del Estudiante: ";
	cin>>Registro.telefono;
	fwrite(&Registro, sizeof(tipo_registro), 1,archivo);
	fclose(archivo);
	system("pause");
	system("cls");
}
void leer(){
	FILE *archivo = fopen(archivo_tarea1, "r+b");
	tipo_registro Registro;
	fread(&Registro, sizeof(tipo_registro), 1, archivo);
	while(!feof(archivo))
	{
		cout<<"CODIGO: "<<Registro.codigo<<endl;
		cout<<"NOMBRE: "<<Registro.nombre<<endl;
		cout<<"APELLIDO: "<<Registro.apellido<<endl;
		cout<<"DIRECCION: "<<Registro.direccion<<endl;
		cout<<"TELEFONO: "<<Registro.telefono<<endl;
		cout<<"------------------------------------------------"<<endl;
		fread(&Registro, sizeof(tipo_registro), 1, archivo);
	}
	fclose(archivo);
	system("pause");
	system("cls");
}
void modificar(){
	int opc;
	FILE *archivo = fopen(archivo_tarea1, "r+b");
	tipo_registro Registro;
	cout<<"Ingrese el Codigo del Estudiante: ";
	cin>>opc;
	fread(&Registro, sizeof(tipo_registro), 1, archivo);
	if(opc==Registro.codigo)
	{
		cout<<Registro.codigo<<endl;
		cout<<Registro.nombre<<endl;
		cout<<Registro.apellido<<endl;
		cout<<Registro.direccion<<endl;
		cout<<Registro.telefono<<endl;
		cout<<"--------------------------"<<endl;
		cout<<"Ingresa el Nombre del Estudiante: ";
		cin>>Registro.nombre;
		cout<<"Ingrese el Apellido del Estudiante: ";
		cin>>Registro.apellido;
		cout<<"Ingrese la Direccion del Estudiante: ";
		cin>>Registro.direccion;
		cout<<"Ingrese el Telefono del Estudiante: ";
		cin>>Registro.telefono;
		int pos=ftell(archivo)-sizeof(tipo_registro);
		fwrite(&Registro, sizeof(tipo_registro), 1,archivo);
		cout<<"Se Han Modificado los Datos"<<endl;
		fclose(archivo);
		system("pause");
		system("cls");
	}
}
void eliminar(){
	int opc;
	FILE *archivo = fopen(archivo_tarea1, "r+b");
	tipo_registro Registro;
	cout<<"Ingrese el Codigo del Estudiante: ";
	cin>>opc;
	fread(&Registro, sizeof(tipo_registro), 1, archivo);
	if(opc==Registro.codigo)
	{
		int pos=ftell(archivo)-sizeof(tipo_registro);
		fwrite(&Registro, sizeof(tipo_registro), 1,archivo);
		cout<<"Se Eliminado el Estudiante"<<endl;
		fclose(archivo);
		system("pause");
		system("cls");
	}
}

main(){
	int opc;
	do{
		cout<<"Opcion 1: Ingresar los Datos del Estudiante"<<endl;
		cout<<"Opcion 2: Ver listado de Estudiantes"<<endl;
		cout<<"Opcion 3: Modificar Datos del Estudiante"<<endl;
		cout<<"Opcion 4: Eliminar Estudiante"<<endl;
		cout<<"Selecciona una opcion: ";
		cin>>opc;
		system("cls");
		switch(opc)
		{
			case 1: ingreso_datos();
					break;
			case 2: leer();
					break;
			case 3: modificar();
					break;	
			case 4: eliminar();
					break;	
		}
	}while(opc!=5);
	return 0;
}