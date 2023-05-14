#ifndef ITEM_H
#define ITEM_H


#include <iostream> 
#include <stdio.h>

using namespace std; 

class item
{
private: 
	char name[20]; 
	int code[20]; 
	float price[20]; 
	int z; 
public: 
	void add_(void); 
	void delete_(void); 
	void sell_(void); 
	void display_(void); 
	void initial(void){z=0;}
};

#endif