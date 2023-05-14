#include<Objeto.h> 
#include<iostream> 
#include <string>
//-----------------Creación de Objeto ----------------------
Objeto::Objeto(string name, string descrip){
	nombre = name; 
	desc = descrip; 
	marketable_flag = false; 
	usable_flag = false; 
	battle_flag = false; 
	icon_image = "No cargado"; 
}

Objeto::~Objeto(){
	icon_image = "No cargado"; 
}

void Objeto::cargar_imagen(string ruta){
	icon_image = ruta; 
}
//Getter de nombre y descripcion del objeto.
string Objeto::getNombre(){  return nombre; }
string Objeto::getDesc(){ return desc; }
//Getter y setter de objeto para vender. 
void Objeto::setMarketable_flag(bool i){ marketable_flag = i; }
bool Objeto::getMarketable_flag(){ return marketable_flag; }
//Getter y setter de usado normal.
void Objeto::setUsable_flag(bool i){ usable_flag = i; }
bool Objeto::getUsable_flag(){ return usable_flag;}
//Getter y setter de usado en batalla.
void Objeto::setBattle_flag(bool i){ battle_flag = i; }
bool Objeto::getBattle_flag(){ return battle_flag;}

//-----------------Creación de Arma ------------------------
Arma::Arma(string nombre,string desc, int dano_, int costo_):Objeto(nombre,desc){
	dano = dano_; 
	costo = costo_; 
}
int Arma::getDano(){return dano; }
int Arma::getCosto(){return costo;}

void Arma::atributos(){
	cout<<getNombre()<<endl; 
	cout<<getDesc()<<endl; 
	cout<<"Atributos: "<<endl; 
	cout<<".Daño: "<<getDano()<<endl; 
	cout<<".Precio: "<<getCosto()<<endl; 
}


//-----------------Creación de Comida ----------------------
Comida::Comida(string nombre, string desc, string propiedades_, int costo_, int curacion_):Objeto(nombre,desc){
	propiedades = propiedades_; 
	costo = costo_; 
	curacion = curacion_; 
	setUsable_flag(true); //Se puede usar 
	setMarketable_flag(true); //Se puede vender
}
string Comida::getPropiedades(){ return propiedades;}
int Comida::getCosto(){ return costo; }
int Comida::getCuracion(){return curacion;}

void Comida::atributos(){
	cout<<getNombre()<<endl; 
	cout<<getDesc()<<endl; 
	cout<<getPropiedades()<<endl;
	cout<<"Atributos: "<<endl; 
	cout<<".Precio: "<<getCosto()<<endl; 
	cout<<".Curacion: "<<getCuracion()<<endl; 
}
