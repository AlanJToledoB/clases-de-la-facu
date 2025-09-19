#include <iostream>
#include <vector>
using namespace std;

class Tecla{
private:
	bool m_estado;
	string m_nota;
public:
	Tecla(string nombre){
		m_estado = false;
		m_nota = nombre;
	}
	
	string VerNota(){
		return m_nota;
	}
		
	void Apretar(){
		m_estado = true;
	}
	void Soltar(){
		m_estado = false;
	}
		
	bool EstaApretada(){
		if(m_estado){
			return true;
		}else{
			return false;
		}
	}
	
};


class Pedal{
private:
	float presion;
public:
	Pedal(){
		presion = 0.0;
	}
	
	void presionarPedal(float fuerza){
		presion +=fuerza;
	}
		
	float verPresion(){
		return presion;
	}
	
	void soltarPresion(float fuerza){
		presion -=fuerza;
	}
};
	
class Instrumento {
private:
	string m_nombre;
public:
	Instrumento(string nombre) {
		m_nombre = nombre;
	}
	string VerNombre() { return m_nombre; }
	virtual string Sonido() = 0;
	virtual ~Instrumento() { }
};

class Piano : public Instrumento{
private:
	string nombreInstrumento;
	vector <Tecla> teclas;
	Pedal m_pedal;
public:
	Piano( ): Instrumento("Piano"){
		nombreInstrumento = "piano";
		Tecla Tdo ("do");
		Tecla Tre ("re");
		Tecla Tmi ("mi");
		Tecla Tfa ("fa");
		Tecla Tsol ("sol");
		Tecla Tla ("la");
		Tecla Tsi ("si");
		
		teclas.push_back(Tdo);
		teclas.push_back(Tre);
		teclas.push_back(Tmi);
		teclas.push_back(Tfa);
		teclas.push_back(Tsol);
		teclas.push_back(Tla);
		teclas.push_back(Tsi);
	}
	void presionarTecla(string nombreTecla){
		for(int i = 0; i < teclas.size(); i++){
			if(teclas[i].VerNota() == nombreTecla){
				teclas[i].Apretar();
			}
		}
	}
	void soltarTecla(string nombreTecla){
		for(int i = 0; i<teclas.size();i++){
			if(teclas[i].VerNota() == nombreTecla){
				teclas[i].Soltar();
			}
		}
	}
	
	void PresionarPedal(float fuerza){
		m_pedal.presionarPedal(fuerza);
	}
		
	string Sonido() override{
		string sonido;
		for(int i = 0; i<teclas.size(); i++){
			if(teclas[i].EstaApretada()){
				sonido += teclas[i].VerNota();
			}
		}
		return sonido;
	}
};




//hacer funcionar esto con la clase instrumento 
void mostrarEnPantalla(Instrumento *inst) {
	cout << "El " << inst->VerNombre() << " suena: " << inst->Sonido() << endl;
}


int main(int argc, char *argv[]) {
	Piano p1;
	
	
	
	p1.presionarTecla("do");
	
	
	Instrumento *inst = &p1;
	
	
	mostrarEnPantalla(inst);
	
	return 0;
}

