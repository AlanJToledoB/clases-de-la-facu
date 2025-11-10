#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct datosTerna{
	int nroMes;
	float valMax;
	int repeticiones;
	bool operator<(datosTerna d2){
		return valMax > d2.valMax;
	}
};

int main(int argc, char *argv[]) {
	
	ifstream archivo("datos.txt");
	
	if(!archivo.is_open()) throw runtime_error("no se pudo abrir el archivo para leerlo");
	vector<float> mediciones;
	float medicion;
	
	while(archivo>>medicion){
		mediciones.push_back(medicion);
	}
	
	
	vector<datosTerna> mayores;
	for(int i=0;i<12;i++) { 
		float mayMedicion = 0.0;
		int posMedicion = 0;
		int repeticiones = 1;
		datosTerna data;
		for(int j=0;j<30;j++) { 
			
			posMedicion = i * 30 + j;
			

			if(mayMedicion < mediciones[posMedicion]){
				
				mayMedicion = mediciones[posMedicion];
				repeticiones = 1;
			}else if (mediciones[posMedicion] == mayMedicion) {
				repeticiones++;
			}
			
			
			data.nroMes = i + 1;
			data.valMax = mayMedicion;
			data.repeticiones = repeticiones;
			
		}
		mayores.push_back(data);
	}
	
	sort(mayores.begin(), mayores.end());
	
	archivo.close();
	
	fstream archiEscritura("maximos.dat", ios::binary | ios::in | ios::out);
	
	if(!archiEscritura.is_open()) throw runtime_error("no se pudo abrir el archivo para escritura");
	
	for(size_t i=0;i<mayores.size();i++) { 
		archiEscritura.write(reinterpret_cast <char*>(&mayores[i]), sizeof(datosTerna));
	}
	
	return 0;
}

