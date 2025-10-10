#include <iostream>
using namespace std;


int superaProm(float* inicio, float* fin, int &tamanio, float &prom){
	int supera = 0;
	float sumNotas = 0.0;
	for(float* i = inicio; i<fin; i++){ //en estos casos tener en cuenta que es logico queue
		// el indice "i" ya es un puntero que recore EL VECTOR entonces no es necesario 
		//acceder de ninguna otra forma
		sumNotas += *i;
	}
	prom = sumNotas/tamanio;
	
	for(float* i = inicio; i<fin; i++){
		if(*i > prom){
			supera += 1;
		}
	}
	return supera;
}


int main(int argc, char *argv[]) {
	cout<<"cuantos elementos desea agregar al vector?";
	int cantElementos;
	cin>>cantElementos;
	
	float* vec = new float [cantElementos];
	
	cout<<"ahora ingrese lo elementos";
	for(int i = 0; i<cantElementos; i++){
		cin>>*(vec + i);
	}
	
	float* fin = vec + cantElementos;
	
	float promedio = 0.0;//solo para pasarlo como parametro en la funcion
	
	int cantSuperior = superaProm(vec, fin, cantElementos, promedio);
	cout<<"estas son la cantidad de notas que sobrepasan el promedio"<<cantSuperior;
	
	float* soloSuperan = new float [cantSuperior];

	int indiceSumatorio = 0;
	for(float* i= vec; i<fin; i++){ // "i" ya tiene un valor, va agarrando el valor de cada nota. ejem
		if(*i > promedio){          // i = 10, i = 8, i = 4, etc. no es un indice
			*(soloSuperan + indiceSumatorio) = *i; // usamos el indice de abajo para saber donde vamos
			indiceSumatorio ++; //el indice que recorre y dice donde ir imprimiendo
		}
	}
	
	cout << "Notas que superaron el promedio:" << endl;
	for (int i = 0; i < cantSuperior; i++) {
		cout << *(soloSuperan + i) << " "; //aca unicamente se imprimer el vector con aritmetica de punteros
	}
	cout << endl;
	return 0;
}

