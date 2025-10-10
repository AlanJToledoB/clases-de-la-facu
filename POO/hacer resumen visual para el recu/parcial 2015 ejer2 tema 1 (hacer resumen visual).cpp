#include <iostream>
#include <vector>
using namespace std;


class Animal{
private:
	string m_especie;
public:
	Animal(string Tipo, string especie){
		m_especie = especie;
	};
	virtual string desplazarse()=0;
	virtual string tipo() = 0 ;
	string verEspecie(){
		return m_especie;
	}
	
};

class Mamifero:public Animal{
private:
public:
	Mamifero(string especie):Animal("Mamifero", especie){
	
	};
	
	string desplazarse()override{
		return "camina";
		
	}
	string tipo()override{
		return "mamifero";
	}
	
};

class Ave:public Animal{

public:
	Ave(string especie): Animal("ave",especie){};
	
	string desplazarse()override{
		return "vuela";
	}
	
	string tipo()override{
		return "Ave";
	}
};

class Pez:public Animal{

public:
	Pez(string especie): Animal("ave",especie){};
	
	string desplazarse()override{
		return "nada";
	}
	
	string tipo()override{
		return "Pez";
	}
};



int main(int argc, char *argv[]) {
	
	Animal* parque[30];
	
	for(size_t i=0;i<30;i++) { 
		cout<<"animal de tipo: "<<parque[i]->tipo()<< "de especie"<< parque[i]->verEspecie()<<"se desplaza"<<parque[i]->desplazarse();
	}
	
	return 0;
}

