#include <iostream>
#include <list>
#include <fstream>
#include <numeric>
using namespace std;

struct complejo{
	float p_real;
	float p_img;
};

complejo operator+(complejo c1,complejo c2){
	complejo suma;
	suma.p_real = c1.p_real + c2.p_real;
	suma.p_img = c1.p_img + c2.p_img;
	return suma;
}


complejo operator/(complejo c1,int entero){
	complejo Division;
	Division.p_real = c1.p_real/entero;
	Division.p_img = c1.p_img / entero;
	return Division;
}


template <typename T>
T promedio(list<T> datos){
	

	T suma = accumulate(datos.begin(), datos.end(), T{});
	
	return suma/datos.size();
	
}


int main(int argc, char *argv[]) {
	
	list <float> flotantes;
	cout<<"cuantos flotantes desea ingresar";
	int num;
	cin>>num;
	for(int i=0;i<num;i++) { 
		float nume;
		cout<<"ingrese el valor que desea para la lista";
		cin>>nume;
		flotantes.push_back(nume);
	}
	
	float promedioFlotantes = promedio(flotantes);
	
	list <int> enteros;
	
	for(int i=0;i<num;i++) { 
		enteros.push_back(rand()% 101);
	}
	
	float promedioEnteros = promedio(enteros);
	
	list <complejo> complejos;
	ifstream archi("complejos.dat", ios::binary | ios::in | ios::out);
	if(!archi.is_open())throw runtime_error("no se pudo encontrar el archivo para leerlo");
	
	complejo comple;
	while(archi.read(reinterpret_cast<char*>(&comple), sizeof(complejo))){
		complejos.push_back(comple);
	}
	
	complejo promedioComplejo = promedio(complejos);
	
	archi.close();
	
	return 0;
}

