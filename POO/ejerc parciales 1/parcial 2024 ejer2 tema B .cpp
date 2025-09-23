#include <iostream>
using namespace std;

int* filtrar_rango (int *v, int min, int max, int &tamanio){
	
	int cantQuedaAfuera=0;
	
	for(int i = 0; i<tamanio; i++){
		if(v[i]<min || v[i]>max){
			cantQuedaAfuera += 1;
		}
	};
	
	int *nuevoVector = new int [cantQuedaAfuera];
	
	int posicionResultado = 0;
	
	for(int i = 0; i<tamanio; i++){
		if(v[i]<min || v[i]>max){
			nuevoVector[posicionResultado] = v[i];
			//posicionResultado sirve para llevar un índice separado del nuevo arreglo, porque el nuevo 
			//arreglo (nuevoVector) es más chico que el original.
			posicionResultado +=1;
		}
	}
	//cambia el tamanio anterior del vector al nuevo tamanio
	tamanio = cantQuedaAfuera;
	return nuevoVector;
}

int main(int argc, char *argv[]) {
	int tamanio;
	cout<<"cuantos enteros va a querer ingresar a su vector?";
	cin>>tamanio;
	int *v = new int [tamanio];
	
	for(int i = 0; i<tamanio; i++){
		cin>>v[i];
	}
	
	int *v2 = filtrar_rango(v, 3, 5, tamanio); 
	//pasamos el tamanio por referencia para que cambie el nuevo tamanio del nuevo vector
	//en la funcion (de eso se encarga la funcion de arriba)
	for(int i = 0; i<tamanio; i++){
		cout<<v2[i];
	}
	return 0;
}

