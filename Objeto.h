#ifndef OBJETO_H
#define OBJETO_H
#include <iostream> 
#include <string>
using namespace std; 

class Objeto{
private: 
	string nombre; 
	string desc; 
	bool marketable_flag; 
	bool usable_flag; 
	bool battle_flag; 
	string icon_image; 

public: 
	Objeto(string nombre , string desc); 
	~Objeto(); 
	void cargar_imagen(string ruta); 
	string getNombre(); 
	string getDesc(); 
	void setMarketable_flag(bool i); 
	bool getMarketable_flag(); 
	void setUsable_flag(bool i); 
	bool getUsable_flag(); 
	void setBattle_flag(bool i); 
	bool getBattle_flag(); 
};

class Arma: public Objeto{
private: 
	int dano; 
	int costo; 
public: 
	Arma(string nombre, string desc ,int dano_, int costo_);
	void atributos();
	int getDano();
	int getCosto();
};

class Comida: public Objeto{
private: 
	string propiedades; 
	int costo;
	int curacion; 

public: 
	Comida(string nombre, string desc, string propiedades_, int costo_, int curacion_); 
	void atributos(); 
	string getPropiedades(); 
	int getCosto(); 
	int getCuracion(); 
};

class Inventory{
private: 
	int money; 
	template item[];
	//Como hacer que un array me almacene clases?  
public: 

}
#endif