#include <iostream>
using namespace std;
struct punto{
	float x;
	float y;
};

class rectaExplicita{
private:
	float m,b;
	
public:
	
	rectaExplicita(punto p, punto q){
		m = (q.y - p.y)/(q.x - p.x);
		
		b = p.y - m*p.x;
	}
	float verM(){
		return m;
	}
	
	float verB(){
		return b;
	}
	string obtenerEcuacion(){
		string mString = to_string(m);
		string bString = to_string(b);
		
		string ecuacion = mString + " x " + " + " +bString;
		
		return ecuacion;
	}
	
	bool pertenece(punto p){
		
		if(m*p.x + b == p.y){
			return true;
		}else{
			return false;
		}
	}
		
	//ver cual seria la forma de esto con el del float
	
};

int main(int argc, char *argv[]) {
	
	return 0;
}













