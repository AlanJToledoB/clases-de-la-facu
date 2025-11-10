#include <iostream>
#include <fstream>
using namespace std;


template <typename T>
int ocurrencias(string nombre, T datoVer, T reemplazoDato){
	fstream archi(nombre, ios::binary | ios::in | ios::out);
	if(!archi.is_open()) throw runtime_error("no se pudo acceder al archivo para leerlo");
	
	int reemplazos = 0;
	T dato;
	while(archi.read(reinterpret_cast<char*>(&dato),sizeof(T))){
		if(dato == datoVer){
			archi.seekp(-(long) sizeof(T), ios::cur);
			archi.write(reinterpret_cast<char*>(&reemplazoDato), sizeof(T));
			reemplazos++;
		}
	}
	
	archi.close();
	return reemplazos;
}

int main(int argc, char *argv[]) {
	
	return 0;
}

