#include <iostream>
using namespace std;

int* intercala(int* v, int* v1, int vTam, int v1Tam, int &nuevoTam){
	nuevoTam = vTam+v1Tam;
	int* nuevoVec = new int [nuevoTam];
	
	int i = 0, j = 0, k = 0; //k = iterador del vector nuevo,  i = iterador de v, j = iterador de v1
	
	while(i< vTam && j < v1Tam){
		*(nuevoVec + k) = *(v + i);
		k++;
		i++;
		*(nuevoVec + k) = *(v1+j);
		k++;
		j++;
	}
	
	//aca seria por si sobra algun elemento fuera de alguno de los vectores
	while(i<vTam){
		*(nuevoVec + k) = *(v + i);
		k++;
		i++;
	}
	
	while(j<v1Tam){
		*(nuevoVec + k) = *(v1+j);
		k++;
		j++;
	}
	
	
	return nuevoVec;
}

int main(int argc, char *argv[]) {
	cout<<"cuantos elementos tendra el primer vector?";
	int n1;
	cin>>n1;
	
	cout<<"cuantos elementos tendra el segundo vector?";
	int n2;
	cin>>n2;
	
	int* v1 = new int [n1];
	int* v2 = new int [n2];
	
	cout<<"ingrese los "<<n1<<" elmentos del primer vector";
	
	for(int i = 0; i<n1;i++){
		cin>>*(v1 + i);
	}
	
	cout<<"ingrese los "<<n2<<" elmentos del segundo vector";
	
	for(int i = 0; i<n2;i++){
		cin>>*(v2 + i);
	}
	
	int nuevoTamanio = 0;
	int* nuevoVector = intercala(v1,v2,n1,n2,nuevoTamanio);
	
	for(int i = 0; i<nuevoTamanio;i++){
		cout<<*(nuevoVector + i);
	}
	return 0;
}

