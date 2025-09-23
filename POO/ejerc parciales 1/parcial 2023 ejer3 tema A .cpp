#include <iostream>
using namespace std;

int *repetir(int* inicio, int* fin, int m, int &nuevoTmanio){
	int tamanio = fin - inicio; //forma de saber tamanio de vector de punteros con su inicio y su fin
	nuevoTmanio = tamanio * m;
	int *nuevoVector = new int[nuevoTmanio];
	
	int iteradorVector = 0;
	
	for(int* i = inicio; i<fin; i++){
		for(int k = 0; k<m;k++){
			
			nuevoVector[iteradorVector] = *i;
			iteradorVector++;
		}
	}
	return nuevoVector;	
}

int main(int argc, char *argv[]) {
	int cantElementos = 0;
	cout<<"ingrese la cantidad de elementos del vector";
	cin>> cantElementos;
	
	int *A = new int [cantElementos];
	cout<<"cargue los elementos";
	for(int i = 0; i<cantElementos; i++){
		cin>>A[i];
	}
	
	int* inicio = A; //el elemento del puntero siempre marca la posicion de inicio del vector
	int* fin = A + cantElementos; //si sumamos a la posicion inicial la cantidad de elementos que 
					//tenemos vamos a llegar al final
	
	for(int i= 2; i<=5; i++){
		
		int nuevoTamanio;
		int* B = repetir(inicio, fin, i, nuevoTamanio);
		
		cout<<"arreglo con m = "<<i<<": ";
		
		for(int m = 0; m < nuevoTamanio; m++){
			cout<<B[m]<< " ";
		}
		cout<<endl;
		
		
	}
	
	return 0;
}

