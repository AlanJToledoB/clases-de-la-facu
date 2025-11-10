#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template <typename T>
int reemplazar(string nombre, T a, T b){
	ifstream archi(nombre);
	if(!archi.is_open())throw runtime_error("no se pudo encontrar el archivo para leerlo");
	
	///tener en cuenta que tiene que ser para valores genericos
	vector<T> archivo;
	T linea;
	while(getline(archi,linea)){
		archivo.push_back(linea);
	}
	archi.close();
	
	//cuenta apariciones de a
	int apariciones = count(archivo.begin(),archivo.end(), a);
	replace(archivo.begin(), archivo.end(), a,b);
	
	ofstream archivoEsc(nombre);
	if(!archivoEsc.is_open())throw runtime_error("no se pudo escribir en el archivo");
	
	for(size_t i=0;i<archivo.size();i++) { 
		archivoEsc<<archivo[i]<<endl;
	}
	
	return apariciones;
}


int main(int argc, char *argv[]) {
	
	return 0;
}

