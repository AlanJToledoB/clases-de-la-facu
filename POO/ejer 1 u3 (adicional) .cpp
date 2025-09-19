#include <iostream>
#include <vector>
using namespace std;

class Butaca{
private:
	string m_tipo;
	float m_precio;
	bool m_estado;
public:
	Butaca(string tipo, float precio){
		m_tipo = tipo;
		m_precio = precio;
		m_estado = false;
		
		
	}
	
	string VerTipo(){
		return m_tipo;
	}
		
	float VerPrecio(){
		return m_precio;
	}
	
	bool VerEstado(){
		return m_estado;
	}
	
	void cambiarEstado(bool estado){
		m_estado = estado;
	}
	void CambiarTipo(string nuevoTipo){
		m_tipo = nuevoTipo;
	}
		
	void cambiarPrecio(float nuevoPrecio){
		m_precio = nuevoPrecio;
	}
		
};


class sala{
private:
	string m_NombreSala;
	vector <Butaca> Butacas;
public:
	sala(string NombreSala){
		m_NombreSala = NombreSala;
	}
	
	void agregarButacas(int CantButacas, string TipoButaca, float PrecioButaca){
		
		Butaca buta(TipoButaca, PrecioButaca);
		
		for(int i = 0; i < CantButacas; i++){
			Butacas.push_back(buta);
		};
	}
		
	bool realizarCompraButaca(int NumButaca){
		
			if(Butacas[NumButaca].VerEstado()){
				Butacas[NumButaca].cambiarEstado(false);
				return true;
			}else{
				return false;
			}
			
	}
	
	float RecaudacionTotal(){
		float Suma = 0.0;
		
		for(int i = 0; i<Butacas.size(); i++){
			
			if(Butacas[i].VerEstado()){
				Suma += Butacas[i].VerPrecio();
			}
			
		}
		
		return Suma;
		
	}
		
	
	float porcentajeOcupacio(){
		int cantSillasOcupadas = 0;
		
		for(int i = 0; i<Butacas.size(); i++){
			
			if(Butacas[i].VerEstado()){
				cantSillasOcupadas += 1;
			}
			
		}
		return (cantSillasOcupadas / Butacas.size()) *100;
		
	}
	
	
};

int main(int argc, char *argv[]) {
	
	return 0;
}

