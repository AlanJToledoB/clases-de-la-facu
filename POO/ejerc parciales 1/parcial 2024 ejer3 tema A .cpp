#include <iostream>
using namespace std;
class Jugador{
private:
	int m_puntos, m_vida;
public:
	Jugador(int vida){
		m_puntos = 0;
		m_vida = vida;
	}
	
	int verPuntos(){
		return m_puntos;
	}
		
	int verVidas(){
		return m_vida;
	}
		
	void restarVida(){
		m_vida -= 1;
	}
		
	void sumaVida(){
		m_vida += 1;
	}
		
	void sumarPuntos(int puntosSumar){
		m_puntos += puntosSumar;
	}
	
};

class Estrella{
private:
	string m_nombre;
public:
	Estrella(string nombre){
		m_nombre = nombre;
	}
	string verNombre(){
		return m_nombre;
	}
	virtual void aplicar(Jugador& jug) = 0;
};

class EstrellaRoja:public Estrella{
	
public:
	EstrellaRoja():Estrella("Roja"){};
	
	void aplicar(Jugador& jug)override{
		jug.sumaVida();
	}
};

class EstrellaAzul:public Estrella{
private:
	int m_cantPuntos;
	
public:
	EstrellaAzul(int cantPuntos):Estrella("Azul"){
		m_cantPuntos = cantPuntos;
	}
	
	void aplicar(Jugador& jug)override{
		jug.sumarPuntos(m_cantPuntos);
	}
	
};

void aplicarBeneficio(Estrella* estr, Jugador& jug){
	
	cout<<"su jugador choco"<<estr->verNombre()<<endl<<"antes tenia - vida:"<<jug.verVidas()<< " y puntos: "<<jug.verPuntos();
	estr->aplicar(jug);
	cout<<"ahora posee"<<jug.verVidas()<<" vidas y "<< jug.verPuntos()<<" puntos";
	
}

int main(int argc, char *argv[]) {
	
	
	Estrella* estrAzul = new EstrellaAzul(8);
	Jugador jug(10);
	
	aplicarBeneficio(estrAzul, jug);
	
	return 0;
}

