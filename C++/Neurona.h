#ifndef NEURONA_H
#define NEURONA_H

#include <iostream> 
#include <otrosAlgoritmos/Matrix.h>

template <class U> 
class Neurona{

private: 
	int size_n; //n cantidad de neuronas 
	int size_m; //m cantidad de salidas 
	//Matrix <T>* vector;
	//Matrix <T> matrix_pesos(int size_n, int size_m); 

public: 
	Neurona(int n, int m):size_n(n),size_m(m){
		//vector = new Matrix <T>(n,m); 
	}
	
};



#endif