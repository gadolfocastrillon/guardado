#include <iostream>
#include <fstream>

using namespace std; 

template <class T> 
class Matrix{
private: 
	int rows, cols; 
	T* pMatrix; 

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
		pMatrix = new T[rows*cols]; 

		for (int i = 0; i<rows*cols;i++){
			pMatrix[i] = matrix.pMatrix[i];
		}
	}
	//Destructor de la matrix 
	~Matrix(){
		delete[] pMatrix;
	}

	int getrows(){return this->rows;}
	int getcols(){return this->cols;}

	Matrix& operator= (const Matrix& matrix){
		this->~Matrix(); 
		rows = matrix.rows; 
		cols = matrix.cols; 
		pMatrix = new T[rows*cols]; 

		for (int i=0; i<rows*cols;i++){
			pMatrix[i] = matrix.pMatrix[i];
		}
		return *this; 
	}

	bool operator ==(const Matrix& matrix){
		if (rows == matrix.rows && cols == matrix.cols){
			for(int i=0;i<rows*cols;i++){
				if(pMatrix[i] != matrix.pMatrix[i]){
					return false;
				}
			}
			return true; 
		}
		else{
			return false;
		}
	}

	bool operator!= (const Matrix& matrix){
		return 1 - (*this == matrix);
	}

	Matrix operator+ (const Matrix& matrix){
		if(rows == matrix.rows && cols == matrix.cols){
			Matrix result(rows,cols); 
			for (int i=0; i<rows*cols;i++){
				result.pMatrix[i] = pMatrix[i] + matrix.pMatrix[i];
			}
			return result;
		}
	}

	Matrix operator- (const Matrix& matrix){
		if(rows == matrix.rows && cols == matrix.cols){
			Matrix result(rows,cols); 
			for (int i=0; i<rows*cols;i++){
				result.pMatrix[i] = pMatrix[i] - matrix.pMatrix[i];
			}
			return result;
		}
	}

	Matrix operator* (const Matrix& matrix){
		if(cols == matrix.rows){
			Matrix result(rows, matrix.cols);
			for (int i=0;i<rows;i++){
				for(int j=0;j<matrix.cols;j++){
					result.pMatrix[i*result.cols + j] = 0;
					for (int k=0;k<cols;k++){
						result.pMatrix[i*result.cols + j] += pMatrix[i*cols +k] * matrix.pMatrix[k*matrix.cols + j]; 
					}
				}
			}
			return result;
		}
	}

	template<class U>
	friend istream& operator >> (istream& input, Matrix<U>& matrix); 
	template<class U> 
	friend ostream& operator << (ostream& output, const Matrix<U>& matrix);
	template<class U> 
	friend ifstream& operator >>(ifstream& input, Matrix<U>& matrix);
	template<class U> 
	friend ofstream& operator <<(ofstream& output, const Matrix<U>& matrix);
	//Para poder usar cout para imprimir la matrix o almacenar los datos
	//friend istream& operator >> Matrix<T>(istream& input, Matrix& matrix);	
	/*
	template <class U> 
	friend void show(Matrix<U> matrix);
	*/
};

template<typename U> 
istream& operator>> (istream& input, Matrix<U>& matrix){
	for(int i=0; i<matrix.rows*matrix.cols;i++){
		input >> matrix.pMatrix[i];
	}
	return input;
}


template<class U> 
ostream& operator<<(ostream& output, const Matrix<U>& matrix){
	for(int i=0;i<matrix.rows;i++){
		for(int j=0; j<matrix.cols;j++){
			output << matrix.pMatrix[i*matrix.cols + j] <<" ";
		}
		output<<endl;
	}
	return output;
}

template <typename U>
ifstream& operator>> (ifstream& input, Matrix<U>& matrix){
	for(int i=0;i<matrix.rows*matrix.cols;i++){
		input >> matrix.pMatrix[i];
	}
	return input;
} 
template <typename U> 
ofstream& operator<<(ofstream& output, const Matrix<U>& matrix){
	for(int i=0;i<matrix.rows;i++){
		for(int j=0; j<matrix.cols;j++){
			output << matrix.pMatrix[i*matrix.cols + j] <<" ";
		}
		output<<endl;
	}
	return output;
}

template <class T> 
class Neurona{
private: 
	int size_n,size_m; 
	Matrix <T> vector; 

public: 
	Neurona(int n, int m): size_n(n), size_m(n){
		vector = new Matrix <T> (1,size_n);
	}

	void set_neurona(Matrix <T> matrix){
		vector = matrix;
	}
};