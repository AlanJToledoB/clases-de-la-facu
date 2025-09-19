#include <iostream>
using namespace std;
class Fraccion{
private:
	int m_numerador, m_denominador;
public:
	Fraccion(int numerador, int denominador){
		m_numerador = numerador;
		m_denominador = denominador;
	}
	
	float ConvertirADouble(){
		return m_numerador/m_denominador;
	}
	
};

class NumeroMixto{
private:
	Fraccion m_fraccion;
	int m_parteEntera;
public:
	NumeroMixto(int entera, Fraccion fraccion){
	m_fraccion = fraccion;
	m_parteEntera = entera;
	};
	
	NumeroMixto ConvertirADouble(){
		
		NumeroMixto num(m_parteEntera, m_fraccion.ConvertirADouble());
		return num;
	}
}
int main(int argc, char *argv[]) {
	
	return 0;
}

