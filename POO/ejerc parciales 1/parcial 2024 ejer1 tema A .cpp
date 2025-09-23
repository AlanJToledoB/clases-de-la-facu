#include <iostream>
#include <vector>
using namespace std;
class Entrada{
private:
	int m_numeroAsiento;
	string m_tipo;
	float m_precio;
	bool m_disponibilidad;

public:
	Entrada(int numeroAsiento, string Tipo, float precio){
		m_numeroAsiento = numeroAsiento;
		m_tipo = Tipo;
		m_precio = precio;
		m_disponibilidad = true; //siempre que diga true es porque no hay nadie
	}
	
	int numeroAsiento(){
		return m_numeroAsiento;
	}
		
	float verPrecio(){
		return m_precio;
	}
		
	string verTipo(){
		return m_tipo;
	}
		
	bool verEstado(){
		return m_disponibilidad;
	}
		
	bool comprarAsiento(){
		if(m_disponibilidad){
			m_disponibilidad = false;
			return true;
		}else{
			return false;
		}
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
	
	string nombre(){
		return m_nombre;
	}
		
	void habilitarEntradas(string tipo, float precio, int desde, int hasta){
		for(int i = desde; i<hasta; i++){
			entradas.push_back(Entrada (i, tipo, precio));
		}
	}
		
	bool venderEntrada(int num){
		for(int i = 0; i<entradas.size(); i++){
			if(entradas[i].numeroAsiento() == num){
				if(entradas[i].verEstado()){
					entradas[i].comprarAsiento();
					return true;
				}else{
					return false;
				}
			}
		}
		return false;
	};
		
	vector <Entrada> verLista(){
		return entradas;
	}
		
	float calcRecaudacion(){
		float sumRec = 0.0;
		
		for(int i = 0; i<entradas.size(); i++){
			if(entradas[i].verEstado()== false){
				sumRec +=entradas[i].verPrecio();
			}
		}
		return sumRec;
	}
};





int main(int argc, char *argv[]) {
	Show susy("susy plus plus y los compiladores en vivo");
	susy.habilitarEntradas("platea", 15000, 100, 199);
	susy.habilitarEntradas("palco", 8000, 500, 600);
	
	
	cout<<"cuantas entradas desea comprar";
	int cant;
	cin>>cant;
	cout<<"lista de entradas disponibles";
	
	
	for(int j = 0; j < cant; j++){
		int numEntrada = 0;
		for(int i = 0; i<susy.verLista().size(); i++){
			if(susy.verLista()[i].verEstado()){
				cout<<"num: "<<susy.verLista()[i].numeroAsiento()<<" tipo: "<<susy.verLista()[i].verTipo()<<" precio: "<<susy.verLista()[i].verPrecio();
			}
		}
		
		cin>>numEntrada;
		if(susy.venderEntrada(numEntrada)){
			cout<<"se pudo realizar la compra, continue";
		}else{
			cout<<"no se pudo realizar la compra";
		}
		
	}

	cout<<" recaudacion del show"<<susy.calcRecaudacion();
	return 0;
}

