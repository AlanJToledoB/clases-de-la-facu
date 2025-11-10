#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Entrada {
	string nombre;
	unsigned int fecha_hora; //esto nos da un dato del tipo
	
	bool operator<(Entrada ent2){
		return fecha_hora>ent2.fecha_hora; ///te amo comparacion lexicografica.
	}
	
	bool operator==(Entrada ent2){
		return nombre == ent2.nombre ; //tener en cuenta que en el enunciado solo nos pide coparar el nombre, no importa cuando se abrio
	}
};
//aca voy a recibir mis dos historiales y los voy a convinar primero
//recordar que estan acomodados como primeros los mas recientes usados (osea que el ultimo es el mas viejo en usarse)
//hay que tener en cuenta lo de arriba porque para la parte que me pide la mas reciente es importante

vector<Entrada> combinar(vector <Entrada>& v1, vector<Entrada>& v2, int n){
	vector<Entrada> resultado;
	
	for(int i = 0; i < v1.size(); i++){
		resultado.push_back(v1[i]);
	}
	
	for(int i = 0; i<v2.size(); i++){
		resultado.push_back(v2[i]);
	}
	
	sort(resultado.begin(), resultado.end());
	auto it = unique(resultado.begin(), resultado.end()); 
	resultado.erase(it, resultado.end());
	
	
	if(resultado.size() > n){
		resultado.erase(resultado.begin() + n, resultado.end());
	}
	
	return resultado;
}

vector<Entrada> cargarDatosEntrada(string nombreArch){
	ifstream archi(nombreArch);
	
	if(!archi.is_open()) throw runtime_error("no se pudo abrir el archivo para leerlo");
	
	vector<Entrada> historial;
	string resto;
	unsigned int fecha;
	while(archi>>fecha){
		
		getline(archi,resto);
		
		if(resto[0] == ' '){
			resto.erase(0, 1);
		}
		
		//unicamente cargamos en una estructura y luego cargamos los datos
		Entrada e;
		e.fecha_hora = fecha;
		e.nombre = resto;
		
		historial.push_back(e);
		
	}
	
	return historial;
}
	
	
	
int main(int argc, char *argv[]) {
	
	vector <Entrada> historial1 = cargarDatosEntrada("lista1.txt");
	vector <Entrada> historial2 = cargarDatosEntrada("lista2.txt");
	
	vector <Entrada> historialConjunto = combinar(historial1,historial2, 20 );
	
	ofstream archivo("lista_comb.txt");
	
	if(!archivo.is_open()) throw runtime_error("no se pudo crear el archivo para cargarlo");
	
	for(size_t i=0;i<historialConjunto.size();i++) { 
		archivo<<historialConjunto[i].fecha_hora <<" " <<historialConjunto[i].nombre;
	}
	
	return 0;
}

