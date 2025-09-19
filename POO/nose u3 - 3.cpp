#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Monomio{
private:
	float m_coeficiente;
	float m_exponente;
public:
	Monomio(float coeficiente, float exponente){
		m_coeficiente = coeficiente;
		m_exponente = exponente;
	}
	float Evaluar(int x){
		return m_coeficiente *(pow(x,m_exponente));
	}
	float verExponente(){
		return m_exponente;
	}
		
	float verCoeficiente(){
		return m_coeficiente;
	}
};

class Polinomio{
private:
	vector <Monomio> m_monomios;
	int m_grado;
public:
	Polinomio(int grado){
		m_grado = grado;
	}
	
	float evaluar(int x){
		float evaluado = 0.0;
		for(int i = 0; i < m_monomios.size(); i++){
			evaluado += m_monomios[i].verCoeficiente() * (pow(x,m_monomios[i].verExponente() ));
		}
		
		return evaluado;
	}
	
};

//¿Qué relación debe haber entre las clases Monomio y Polinomio?

//la relacion que debe de haber entre las clases es de composicion
int main(int argc, char *argv[]) {
	
	return 0;
}

