#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
struct pelicula{
	string titulo;
	int fecha;
	float calificacion;
};

bool menorCalf(pelicula peli){
	return peli.calificacion < 4;
}

bool menorQue(pelicula peli1, pelicula peli2){
	return peli1.fecha < peli2.fecha; 
}
	
void filtrarLista(vector <pelicula>& lista, int N){
	
	//removiendo todos los menores a 4
	auto it = remove_if(lista.begin(), lista.end(), menorCalf);
	lista.erase(it, lista.end());
	
	sort(lista.begin(), lista.end(), menorQue);
	
	if(lista.size() > N){
		lista.erase(lista.begin() + N, lista.end());
	}
	
}

int main(int argc, char *argv[]) {
	fstream archi("vistas.dat", ios::binary | ios::in | ios::out);
	
	if(!archi.is_open()) throw runtime_error(" no se pudo encontrar el archivo");
	
	vector<pelicula> peliculas;
	pelicula peli;
	while(archi.read(reinterpret_cast<char*>(&peli),sizeof(pelicula))){
		
		peliculas.push_back(peli);
		
	}
	
	filtrarLista(peliculas, 20);
	
	return 0;
}

