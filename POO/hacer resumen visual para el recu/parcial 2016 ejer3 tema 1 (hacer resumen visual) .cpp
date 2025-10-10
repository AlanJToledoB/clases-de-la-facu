#include <iostream>
using namespace std;

class Envase{
private:
	float m_volumen, m_peso;
public:
	
	void asignarPeso(float p){
		m_peso = p;
	}
	
	virtual float verVolumen() = 0;
	
	float verPeso(){
		return m_peso;
	}
	
};

class Lata: public Envase{
private:
	float m_radio, m_altura;
public:
	Lata(float radio, float altura, float peso){
		asignarPeso(peso);
		m_radio = radio;
		m_altura = altura;
	}
	
	float verVolumen()override{
		return (3.1416 * m_radio * m_radio) * m_altura;
	}

};

class Caja: public Envase {
private:
	float m_largo, m_ancho, m_alto;
public:
	Caja(float largo, float ancho, float alto, float peso){
		m_largo = largo;
		m_ancho = ancho;
		m_alto = alto;
		asignarPeso(peso);
	}
	
	
	
	float verVolumen()override{
		return m_largo * m_ancho * m_alto;
	}
	
};

int main(int argc, char *argv[]) {
	Envase* enva1 = new  Caja(10, 5, 40, 20);
	
	cout<<"el volumen de la caja es: "<<enva1->verVolumen();
	delete enva1;
	
	enva1 = new Lata(5, 20, 3);
	cout<<"el volumen de la Lata es: "<<enva1->verVolumen();
	return 0;
}

