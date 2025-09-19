#include <iostream>
#include <vector>
using namespace std;
class Rueda{
private:
	int m_rodado;
	
public:
	Rueda(int rodado){
		m_rodado = rodado;
	}
	
	float obtenerPerimetro(){
		return m_rodado * 3.1416 * 2.54;
	}
	
	
	
};


class Transmision{
private:
	vector <int> m_tamanioPinones;
	int m_cambio;
	int m_Corona;
public:
	Transmision(vector <int> tamanioPinones, int corona){
		m_tamanioPinones = tamanioPinones;
		m_Corona = corona;
		m_cambio = m_tamanioPinones[0];
	}
	
	void subirCambio(){
		
		if(m_cambio < m_tamanioPinones.size()){
			m_cambio +=1;
		}
		
	}
		
	void bajarCambio(){
		if(m_cambio > m_tamanioPinones[0]){
			m_cambio -=1;
		}
	}
	
	int verCambioActual(){
		return m_cambio;
	}
	
	float calcRelacion(){
		return m_Corona / m_cambio;
	}
		
	
};


class Bicicleta{
private:
	Transmision m_transmision;
	Rueda m_rDelantera;
	Rueda m_rTrasera;
public:
	Bicicleta(vector <int> tamanioPinones, int corona, int rodado1, int rodado2): m_transmision(tamanioPinones, corona),m_rDelantera(rodado1),m_rTrasera(rodado2){};
	
	float velocidadAvanzaEnKh(float vueltasPorMin){
		return vueltasPorMin * m_transmision.calcRelacion() * 0.0006;
	}

};
int main(int argc, char *argv[]) {
	
	return 0;
}

