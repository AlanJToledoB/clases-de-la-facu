#include <iostream>
#include <vector>
using namespace std;

class Alumno{
private:
	string m_nombre;
	int m_DNI, m_nota_final;
public:
	Alumno(string nombre, int DNI, int nota_final){
		m_nombre = nombre;
		m_DNI = DNI;
		m_nota_final = nota_final;
	}	
	
	char condicion(){
		if(m_nota_final < 4){
			return 'L';
		}else if(m_nota_final >= 4){
			return 'R';
		}
	}
	string nombreAlumno(){
		return m_nombre;
	}
	
	int notaFinal(){
		return m_nota_final;
	}
	
	int DNI(){
		return m_DNI;
	}
};

class Materia{
private:
	string m_nombre;
	string m_nombreProfesor;
	vector <Alumno> m_alumnos;
	
public:
	Materia(string nombre, string nombreProfe){
		m_nombre = nombre;
		m_nombreProfesor = nombreProfe;
	}
	
	void agregarAlumno(string nombre, int DNI, int nota_final){
		m_alumnos.push_back(Alumno(nombre, DNI, nota_final));
	}
	
	int cantRegulares(){
		int cantReg = 0;
		for(int i = 0; i<m_alumnos.size();i++){
			if(m_alumnos[i].condicion() == 'R'){
				cantReg++;
			}
		}
		return cantReg;
	}
	int cantLibres(){
		int cantLibres = 0;
		for(int i = 0; i<m_alumnos.size();i++){
			if(m_alumnos[i].condicion() == 'L'){
				cantLibres ++;
			}
			
		}
		return cantLibres;
	}
};


int main(int argc, char *argv[]) {
	
	return 0;
}

