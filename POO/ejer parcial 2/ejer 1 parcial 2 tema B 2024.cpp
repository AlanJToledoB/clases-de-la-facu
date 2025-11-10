#include <iostream>
using namespace std;

struct url_s{
	string protocolo, dominio, directorio, parametros;
	
};

//ejemplo de url “http://unl.edu.ar/ii/parciales?materia=poo");

// Para ordenar los dominios (sort)
bool ordenarPorDominio(url_s ur1, url_s ur2){
	return ur1.dominio < ur2.dominio;
}

	
	// Para eliminar dominios repetidos (unique)
bool mismoDominio(url_s ur1, url_s ur2){
	return ur1.dominio == ur2.dominio;
}

	
url_s separar(string url){
	url_s direccionSeparada;
	size_t pos_protocolo = url.find("://",0);
	
	direccionSeparada.protocolo = url.substr(0,pos_protocolo);
	//direccion del inicio luego del protocolo
	size_t inicio = pos_protocolo + 3;
	//ya nos posicionamos en otra posicion de inicio
	
	//todas estas son las posiciones donde terminan dicha cosa, en este caso donde
	//finaliza el dominio
	size_t pos_dominio = url.find('/', inicio);
	direccionSeparada.dominio = url.substr(inicio, pos_dominio - inicio);
	inicio = pos_dominio + 1;
	
	
	
	if(url.find('?', inicio) != string::npos){
		size_t pos_directorio = url.find('?', inicio);
		direccionSeparada.directorio = url.substr(inicio, pos_directorio - inicio);
		inicio = pos_directorio + 1;
		
		direccionSeparada.parametros = url.substr(inicio, url.length);
	}else{
		direccionSeparada.directorio = url.substr(inicio, url.length());
		return direccionSeparada;
	}
	
	return direccionSeparada;
	
}


list<url_s> unir(list <string>urls){
	
	url_s direccion;
	list <url_s> direccionesUnidas;
	for(auto it = urls.begin(); it != urls.end(); ++it){
		
		direccion = separar(*it);
		
		direccionesUnidas.push_back(direccion);
		
	}
	
	direccionesUnidas.sort(ordenarPorDominio);
	direccionesUnidas.unique(mismoDominio);
	
	return direccionesUnidas;
	
	
}
	
int main(int argc, char *argv[]) {
	
	return 0;
}

