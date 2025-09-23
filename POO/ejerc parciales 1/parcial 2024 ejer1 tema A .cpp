#include <iostream>
#include <vector>
using namespace std;

class Entrada{
private:
	int m_numAsiento;
	string m_tipo;
	float m_precio;
	bool m_estado;
public:
	Entrada(int numAsiento, string tipo, float precio){
		m_numAsiento = numAsiento;
		m_tipo= tipo;
		m_precio = precio;
		m_estado = false;
	}
	
	float consultarPrecio(){
		return m_precio;
	}
		
	bool verEstado(){
		return m_estado;
	}
		
	void cambiarEstado(bool tipo){
		m_estado = tipo;
	}
		
	string verTipo(){
		return m_tipo;
	}
	
	int verNumero(){
		return m_numAsiento;
	}
	
	float verPrecio(){
		return m_precio;
	}
};


class Show{
private:
	string m_nombre;
	vector <Entrada> entradas;
public:
	Show(string nombre){
		m_nombre = nombre;
	}
	
	string consultarNombre(){
		return m_nombre;
	}
		
	void habilitarEntradas(string tipo, float precio, int desde, int hasta){
		
		for(int i = desde; i<hasta ; i++){
			entradas.push_back(Entrada(i,tipo, precio));
		}
		
	}
		
	bool venderEntrada(int num){
		
		for(int i = 0; i<entradas.size(); i++){
			if(num == entradas[i].verNumero() and entradas[i].verEstado() == false){
				entradas[i].cambiarEstado(true);
				return true;
			}
			
		}
		return false;
	}

	vector <Entrada> &listaEntradas(){
		return entradas;
	}
		
	float calRecaudacion(){
		float sumaVendidas = 0.0;

		
		for(int i = 0; i<entradas.size(); i++){
			if(entradas[i].verEstado()){
				sumaVendidas += entradas[i].verPrecio();
			}
		}
		return sumaVendidas;
	}
};



int main(int argc, char *argv[]) {
	Show primerFun("Susy plus plus y los compiladores en vivo");
	
	primerFun.habilitarEntradas("platea", 15000, 100, 199);
	primerFun.habilitarEntradas("palco", 8000, 500, 650);
	
	int cantEntradasVender = 0;
	cout<<"cuantas entradas desea comprar";
	cin>>cantEntradasVender;

	cout<<"lista de entradas disponibles: "<<endl;
	vector <Entrada> &entradas = primerFun.listaEntradas();;
	
	int numEntrada;
	
	for(int i = 0; i<cantEntradasVender; i++){
		
		for(int i = 0; i<entradas.size(); i++){
			if(!entradas[i].verEstado()){
				cout<<"numero entrada: "<<entradas[i].verNumero()<<" tipo de entrada: "<<entradas[i].verTipo() << " precio:" << entradas[i].verPrecio()<<endl;
			}
		}
		cout<<"ingrese el numero de entrada que desea comprar: ";
		cin>>numEntrada;
		bool comprobarDisponbible = primerFun.venderEntrada(numEntrada);
		if(comprobarDisponbible){
			cout<<"la entrada se compro con exito, continue"<<endl;
		}else{
			cout<<"entrada no disponible"<<endl;
		}
	}
	
	cout<<"recaudacion del show : "<<primerFun.calRecaudacion();
	
	return 0;
}

