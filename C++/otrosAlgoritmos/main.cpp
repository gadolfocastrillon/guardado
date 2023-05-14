#include <Matrix.h>

using namespace std; 

int main(){
	fstream fin("ma.txt");
	fstream fon("me.txt"); 

	Matrix<int> A(3); 
	Matrix<int> B(1,3); 
	fin>> A; 
	fon>> B;
	cout<<"La matrix A es: "<<endl; 
	cout<< A;
	cout<<"La matrix B es: "<<endl;
	cout<< B;  
	cout<<"La suma de matrices es: "<<endl; 
	cout<<A+A; 
	cout<<"La resta de matrices es: "<<endl; 
	cout<<A-A; 
	cout<<"La multiplicación de matrices es: "<<endl; 
	cout<<B*A;
	//Matrix<int> B(1,2); 
	
	//cin>>B;

	//cout<<B;

	//cout<< A == B;

	fin.close();


	return 0; 
}