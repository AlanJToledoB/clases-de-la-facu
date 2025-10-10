#include <iostream>
using namespace std;


bool pertenece(int* v, int* vFin, int num){
	
	for(int* i= v; i<vFin; i++){
		if(*i == num){
			return true;
		}
	}
	return false;
	
}

int* repetidosDelete(int* v, int* vFin, int& nuevoTam){
	int tamanio = vFin - v;
	int* nuevo = new int [tamanio];
	int nuevoTamanio = 0;
	
	for(int* p = v; p<vFin; p++){
		bool repetido = false;
		for(int* q = nuevo; q<nuevo + nuevoTamanio ; q++){
			if(*p == *q){
				repetido = true;
				break;
				
			}
		}
			
		if(!repetido){
			*(nuevo+nuevoTamanio) = *p;
			nuevoTamanio ++;
		}
		
	}
	
	int* resultante = new int[nuevoTamanio];
	for(int i = 0; i< nuevoTamanio; i++){
		*(resultante + i ) = *(nuevo + i);
	}
	delete []nuevo;
	nuevoTam = nuevoTamanio;
	return resultante;
	
}
	
	
int main(int argc, char *argv[]) {
	cout<<"cuanto elementos desea cargar en el vector?";
	int n;
	cin>>n;
	int* vRep = new int[n];
	for(int* i = vRep; i<vRep + n; i++){
		
		cin>>*i;
	}
	
	cout<<"su vector sin elementos repetidos quedo: ";
	int* nuevoVec = repetidosDelete(vRep, vRep +n , n);
		
	for(int* i = nuevoVec; i<nuevoVec + n; i++){
		cout<<*i;
	}
	return 0;
}

