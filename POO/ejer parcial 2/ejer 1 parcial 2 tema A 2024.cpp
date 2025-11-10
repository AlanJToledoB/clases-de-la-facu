#include <iostream>
#include <list>
using namespace std;

list <string> to_list(string& s){
	
	list<string> resultado;
	size_t start = s.find('{');
	size_t end = s.find('}');
	
	if(start == string::npos || end == string::npos){
		return resultado;
	}
	
	//extraemos todas las palabras entre llaves
	string contenido = s.substr(start + 1, end - start - 1);
	//el segundo argumento dice la cantidad de elementos que deseamos
	//agarrar luego del primero, en este caso si tiene 14 elementos
	//vamos a agarrar los que sobraron, que seria 14 - el inicio -1
	//menos 1 porque ese uno seria el primero que ya se agarro sumandole en
	//el primer parametro
	
	//aca separamos por comas
	size_t pos_ini = 0;
	while(true){
		size_t pos_coma = contenido.find(',', pos_ini);
		string elemento;
		
		if(pos_coma == string::npos){
			elemento = contenido.substr(pos_ini);
		}else{
			elemento = contenido.substr(pos_ini, pos_coma - pos_ini);
		}
		
		if(!elemento.empty()){
			resultado.push_back(elemento);
		}
		
		if(pos_coma == string::npos)
			break;
		
		pos_ini = pos_coma+1;
	}
	
	return resultado;
}
	
	
	//yo recibo por ejemplo = : "FuPro", "POO", "AED"
	//y tengo que devolver =  "{FuPro,POO,AED,Ing Soft}"
	
string to_string(list <string>& s){
	string resultante = "{";

	
	for(auto it = s.begin(); it != s.end(); ++it){
		
		resultante += *it;
		resultante += 	",";
	}
	
	if (resultante.back() == ',')
		resultante.pop_back();
	
	resultante +="}";
	return resultante;
	
	
}

bool reemplazar (string& lista, string& vieja, string& nueva){
	
	list<string> materias = to_list(lista);
	
	bool encontrado = false;
	for(auto it = materias.begin(); it != materias.end(); ++it){
		if(*it == vieja){
			*it = nueva;
			encontrado = true;
		}
	}
	
	if(encontrado){
		lista = to_string(materias);
		
		return true;
	}else{
		return false;
	}
	
}
	
int main(int argc, char *argv[]) {
	
	return 0;
}

