#include <iostream>
using namespace std;
//parte a)
struct Punto{
	int x;
	int y;
};

class RectaGeneral{
private:
	float a, b, c;
public:
	RectaGeneral(Punto p, Punto q){
		a = q.y - p.y;
		b = p.x - q.x;
		c = -a*p.x - b * p.y;
		
	}
	float verA(){
		return a;
	}
	float verB(){
		return b;
	}
	float verC(){
		return c;
	}
	string obtenerEcuacion(){
		return to_string(a) + "x + " + to_string(b) + "x +" + to_string(c);
	}
	bool pertenece(Punto p){
		if( a * p.x + b * p.y + c == 0){
			return true;
		}else{
			return false;
		}
	}
	
};

int main(int argc, char *argv[]) {
	
	return 0;
}

