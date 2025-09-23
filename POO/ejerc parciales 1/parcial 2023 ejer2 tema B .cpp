#include <iostream>
using namespace std;

int *espejo(int* inicio, int* fin, int& nuevoTamanio){
	int tamanio = fin - inicio;
	nuevoTamanio = (tamanio * 2) - 1;
	int* nuevoVector = new int [(tamanio * 2)- 1];
	
	int Iterador= 0;
	for(int *i = inicio; i<fin;i++){ //este for itera en la posicion de memoria del otro vector
		//(por eso es posible recorrerlo)
		nuevoVector[Iterador] = *i; // va cambiando con cada valor int del vector viejo
		Iterador ++;
	}
	
	//porque fin - 2? fin apunta a un elemento fuera del vector, fin -1 estaria apuntando al ultimo
	//y como en este ejercicio nos pide descartar el ultimo al copiarlo debemos acceder a uno antes del ultimo
	for(int *i = fin - 2 ; i >= inicio ; i--){
		nuevoVector[Iterador] = * i;
		Iterador ++;
	}
	
	return nuevoVector;
}

int main(int argc, char *argv[]) {
	cout<<"ingrese la cantidad de elementos de su vector";
	int n;
	cin>>n;
	
	int *v = new int [n];
	
	cout<<"cargue los datos de su vector";
	for(int i = 0; i<n;i++){
		cin>>v[i];
	}
	
	int newTamanio;
	int* nuevoVector = espejo(v, v + n, newTamanio);
	
	cout<<"nuevo vector";
	for(int i = 0; i<newTamanio;i++){
		cout<<nuevoVector[i]<<endl;
	}
	
	return 0;
}

