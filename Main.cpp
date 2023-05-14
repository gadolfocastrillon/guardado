#include <Objeto.h>
#include <iostream>

using namespace std;
int main(){
	Objeto manzana("Manzana","Objeto comestible que regenera vida"); 
	manzana.setUsable_flag(true); 
	manzana.setMarketable_flag(true); 
	
	Arma katana("katana","Objeto que corta",5,10); 
	katana.atributos();
	Comida pera("Pera", "Objeto comestible", "Este objeto regenera 10 de vida",5,10); 
	pera.atributos();
}