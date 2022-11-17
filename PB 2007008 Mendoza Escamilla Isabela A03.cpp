#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

int* item, * year, registros, desicion, n = 1;
string* nombre, * clasificacion, * caracteristicas, * descripcion, * genero;
float* precio, * iva, * total;

void Alta();
void Eliminar();
void Lista();
void Modificar();
void Archivo();

int main()
{
	int opcion;
	printf("\t ***Videojuegos Gamepo***\n");
	printf(" 1.- Agregar Articulo \n 2.- Modificar Articulo \n 3.- Eliminar Articulo \n 4.- Lista de Articulos \n 5.- Limpiar Pantala \n 6.- Salir \n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		Alta();
		system("pause");
		return main();
		break;

	case 2:
		Modificar();
		system("pause");
		return main();
		break;

	case 3:
		Eliminar();
		system("pause");
		return main();
		break;

	case 4:
		Lista();
		system("pause");
		return main();
		break;

	case 5:
		system("cls");
		return main();
		break;

	case 6:
		Archivo();
		printf("saliendo... \n");
		exit(1);
		break;

	default:
		printf("ingrese otra opcion \n");
		system("pause");
		return main();
		break;
	}
}

void Alta() {
	printf("Cuantos registros desea dar de alta \n");
	scanf_s("%d", &registros);
	item = new int[registros];
	year = new int[registros];
	nombre = new string[registros];
	clasificacion = new string[registros];
	caracteristicas = new string[registros];
	descripcion = new string[registros];
	genero = new string[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];

	for (int i = 0; i < registros; i++) {
		printf("ingrese el  numero del articulo \n");
		scanf_s("%d", &item[i]);
		do {
			if (item[i] != item[i - n]) {
				n = n + 1;
			}
			else {
				printf("el articulo ya existe \n");
				printf("ingrese el numero articulo \n");
				scanf_s("%d", &item[i]);
			}
		} while (n < registros);
		printf("ingrese el nombre del articulo \n");
		cin.ignore();
		getline(cin, nombre[i]);
		printf("ingrese la fecha de lanzamiento del articulo \n");
		scanf_s("%d", &year[i]);
		printf("ingrese la clasificacion del articulo \n");
		cin.ignore();
		getline(cin, clasificacion[i]);
		printf("ingrese las caracteristicas del articulo \n");
		getline(cin, caracteristicas[i]);
		printf("ingrese el genero del articulo \n");
		getline(cin, genero[i]);
		printf("ingrese la descripcion del articulo \n");
		getline(cin, descripcion[i]);
		printf("ingrese el precio del articulo \n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
	}
}

void Eliminar() {
	int eliminar;
	printf("ingrese el numero de articulo que desea eliminar \n");
	scanf_s("%d", &eliminar);

	for (int i = 0; i < registros; i++) {
		if (eliminar == item[i]) {
			item[i] = 0;
		}
	}
}

void Lista() {

	int opc;
	string busq;

	printf("1.- clasificasion \n 2.-genero \n 3. salir \n");
	scanf_s("%d", &opc);
	switch (opc) {
	case 1:
		printf("ingrese la clasificacion a buscar \n");
		cin.ignore();
		getline(cin, busq);
		for (int i = 0; i < registros; i++) {
			if (clasificacion[i] == busq) {
				if (item[i] != 0) {
					printf("articulo: %d \n", item[i]);
					printf("fecha de lanzamiento: %d \n", year[i]);
					printf("videojuego: %s \n", nombre[i].c_str());
					printf("clasificacion: %s \n", clasificacion[i].c_str());
					printf("genero: %s \n", genero[i].c_str());
					printf("caracteristicas: %s \n", caracteristicas[i].c_str());
					printf("descripcion: %s \n", descripcion[i].c_str());
					printf("precio: %f \n", precio[i]);
					printf("iva: %f \n", iva[i]);
					printf("total: %f \n", total[i]);
				}
			}
		}
		system("pause");
		return Lista();
		break;

	case 2:
		printf("ingrese el genero a buscar \n");
		cin.ignore();
		getline(cin, busq);
		for (int i = 0; i < registros; i++) {
			if (clasificacion[i] == busq) {
				if (item[i] != 0) {
					printf("articulo: %d \n", item[i]);
					printf("fecha de lanzamiento: %d \n", year[i]);
					printf("videojuego: %s \n", nombre[i].c_str());
					printf("clasificacion: %s \n", clasificacion[i].c_str());
					printf("genero: %s \n", genero[i].c_str());
					printf("caracteristicas: %s \n", caracteristicas[i].c_str());
					printf("descripcion: %s \n", descripcion[i].c_str());
					printf("precio: %f \n", precio[i]);
					printf("iva: %f \n", iva[i]);
					printf("total: %f \n", total[i]);
				}
			}
		}
		system("pause");
		return Lista();
		break;

	case 3:
		printf("saliendo... \n");
		break;

	default:
		printf("ingrese otra opcion \n");
		system("pause");
		return Lista();
		break;
	}
}

void Modificar() {
	int modificar, modopc, modiopc = 1;

	do {
		printf("ingrese el numero de articulo que desea modificar \n");
		scanf_s("%d", &modificar);
	} while (modificar <= 0);
	for (int i = 0; i < registros; i++) {
		if (modificar == item[i]) {
			printf(" \t Que desea modificar del articulo? \n");
			printf("1.- todo \n 2.- clasificacion \n 3.- genero\n 4.- salir \n");
			scanf_s("%d", &modopc);

			switch (modopc) {
			case 1: 
				printf("ingrese el nombre del articulo \n");
				cin.ignore();
				getline(cin, nombre[i]);
				printf("ingrese la fecha de lanzamiento del articulo \n");
				scanf_s("%d", &year[i]);
				printf("ingrese la clasificacion del articulo \n");
				cin.ignore();
				getline(cin, clasificacion[i]);
				printf("ingrese las caracteristicas del articulo \n");
				getline(cin, caracteristicas[i]);
				printf("ingrese el genero del articulo \n");
				getline(cin, genero[i]);
				printf("ingrese la descripcion del articulo \n");
				getline(cin, descripcion[i]);
				printf("ingrese el precio del articulo \n");
				scanf_s("%f", &precio[i]);
				iva[i] = precio[i] * .16;
				total[i] = precio[i] + iva[i];
				break;

			case 2: 
				printf("ingrese la clasificacion del articulo \n");
				cin.ignore();
				getline(cin, clasificacion[i]);
				break;

			case 3: 
				printf("ingrese el genero del articulo \n");
				cin.ignore();
				getline(cin, genero[i]);
				break;

			case 4:
				break;
				return Modificar();

			default:
				printf("ingrese otra opcion \n");
				system("pause");
				return Modificar();
				break;
			}
		}
	}

}

void Archivo() {
	ofstream archivo;
	string nombrearchivo;

	printf("ingrese el nombre del archivo \n");
	cin.ignore();
	getline(cin, nombrearchivo);

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail()) {
		printf(" ERROR");
		system("pause");
		exit(1);
	}

	for (int i = 0;i < registros;i++) {
		if (item[i] != 0) {
			archivo << " dato\n" << i + 1 << endl;
			archivo << "\t Articulo: " << item[i] << endl;
			archivo << "\t nombre:" << nombre[i] << endl;
			archivo << "\t lanzamiento: " << year[i] << endl;
			archivo << "\t descripcion: " << descripcion[i] << endl;
			archivo << "\t clasificacion: " << clasificacion[i] << endl;
			archivo << "\t caracteristicas: " << caracteristicas[i] << endl;
			archivo << "\t genero: " << genero[i] << endl;
			archivo << "\t precio: " << precio[i] << endl;
			archivo << "\t iva: " << iva[i] << endl;
			archivo << "\t total: " << total[i] << endl;

		}
	}
	archivo.close();
}
	
