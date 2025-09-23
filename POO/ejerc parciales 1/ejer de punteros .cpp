#include <iostream>
using namespace std;

int* copia_sin_x(int* v, int x, int& tamanio){
	int contAparicionX = 0;
	int* fin = v + tamanio;
	for(int* i = v; i<fin;i++){
		if(*i == x) {
			contAparicionX++;
		}
	}
	
	int nuevoTamanio = tamanio - contAparicionX;
	int* nuevoVec = new int [nuevoTamanio];
	int* finNuevo = nuevoVec + nuevoTamanio ;
	
	int aux=0;
	for(int* i = v; i<fin;i++){
		if(*i != x){
			*(nuevoVec + aux) = *i;
			aux++;
		}
	}
	tamanio = nuevoTamanio;
	return nuevoVec;
}

int main(int argc, char *argv[]) {
	
	cout<<"cuantos elementos desea ingresar al vector";
	int cant;
	cin>>cant;
	
	int* vec = new int[cant];
	int* fin = vec + cant;
	cout<<"ingrese uno por uno esos elementos:";
	
	int aux = 0;
	for(int* i = vec; i < fin; i++){
		cin>>*i ;
	}
	
	cout<<"ingrese el entero que desea eliminar de la lista";
	int ent;
	cin>>ent;
	int* nuevoVec = copia_sin_x(vec, ent, cant);
	
	cout<<"nueva lista";
	int* nuevoFin = nuevoVec + cant;
	int aux2;
	for(int* i = nuevoVec; i<nuevoFin;i++){
		cout<<*i;
	}
	
	return 0;
}

