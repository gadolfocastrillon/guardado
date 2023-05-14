#include <iostream> 

using namespace std; 

template <class T> class Matrix{
private: 
	int rows, cols; 
	int pMatrix; 
public: 
	Matrix(int Rows, int Cols){
		rows = Rows; 
		cols = Cols; 
		pMatrix = new T[rows*cols]; 
	}
	Matrix(int size){
		rows = size; 
		cols = size; 
		pMatrix = new T[rows*cols];
	}
	Matrix(const Matrix& matrix){
		rows = matrix.rows; 
		cols = matrix.cols; 
		pMatrix	 = new T[rows*cols]; 
		for (int i = 0; i<rows*cols;i++){
			pMatrix[i] = matrix.pMatrix[i]; 
		}
	}
	~Matrix(){
		delete[] pMatrix;
	}
	friend istream& operator >> <T>(istream& input, Matrix& matrix);
};
template <typename T> 
istream& operator >> (istream& input, Matrix& matrix){
	for(int i=0; i<matrix.rows() * matrix.cols();i++){
		input >> matrix.pMatrix[i];
	}
	return input;
}