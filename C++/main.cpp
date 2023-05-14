//#include<Neurona.h>
#include<otrosAlgoritmos/Matrix.h> 
#include<iostream> 
#include<fstream> 

int main(){
	fstream fin("otrosAlgoritmos/ma.txt");
	fstream fon("otrosAlgoritmos/me.txt"); 

	Matrix<int> A(3); 
	Matrix<int> B(1,3); 
	Neurona<int> neu(3,3);
	fin>> A; 
	fon>> B;
	//cout<<A;
	cout<<B;
	neu.set_neurona(B);

}		