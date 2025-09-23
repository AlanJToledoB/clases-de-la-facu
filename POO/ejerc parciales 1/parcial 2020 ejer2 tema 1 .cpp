#include <iostream>
#include <vector>
using namespace std;

class LogSystem{
public:
	virtual void registrarMensaje(string mensaje)=0;
	virtual void finalizar()=0;
	virtual ~LogSystem(){};
};

class vectorLogger: public LogSystem{
private:
	vector <string> mensajes;
public:
	
	void registrarMensaje(string mensaje) override{
		mensajes.push_back(mensaje);
	}
	
	void finalizar(){
		for(int i = 0; i<mensajes.size(); i++){
			cout<<mensajes[i]<<endl;
		}
	}
};


class coutLogger: public LogSystem{
	
public:
	
	void registrarMensaje(string mensaje)override{
		cout<<mensaje;
	}

	void finalizar()override{
		
	}
	
	
	
};

void obtenerBeneficiados(int n, LogSystem& log) {
	log.registrarMensaje("Cargando archivo de datos");
	vector<Alumnos> v = cargarDatos("alumnos.dat");
	log.registrarMensaje("Filtrando Insuficientes");
	for(Alumno &a : v)
		filtrarInsuficientes(a.notas);
	log.registrarMensaje("Recalculando promedios");
	for(Alumno &a : v)
		a.prom = calcularPromedio(a.notas);
	log.registrarMensaje("Ordenando por promedio");
	ordenarVector(v,comparaPorPromedio);
	log.registrarMensaje("Guardando los "+to_string( n )+" mejores");
	v.resize( n );
	guardarDatos("becarios.dat");
	log.finalizar();
}

int main(int argc, char *argv[]) {
	
	int opcion;
	cout << "Elija mecanismo de login: 1) Cout  2) Vector: ";
	cin >> opcion;
	
	if (opcion == 1) {
		CoutLogger log;
		obtenerBeneficiados(10, log);
	} else {
		VectorLogger log;
		obtenerBeneficiados(10, log);
	}
	
	return 0;
}
//el cambio que debemos de realizar en el prototipo es unicamente pasarlo por referencia
//porque entonces permitimos el polimorfismo dinamico

 //ver bien y entender lo que pide este codigo,hacerlo con la tableta
//porque no es muy facil de entender.

