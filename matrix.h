#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	// Constructor, initialize array of zeros.
	Matrix(int rows, int cols);
	
	// Allow user defined set, where will loop through values of matrix
	void setbyusr();

	// Getter for number of  rows
	int getrows() const;

	// Getter for number of  cols
	int getcols() const;

	// Print matrix for visualization	
	void print();

	//Destructor to handle dynamic array
	~Matrix();

	// Overload + opperator so 
	// Matrix A + Matrix B will return vals for a Matrix C
	Matrix operator + (const Matrix &B);

	// Overload * operator so 
	// Matrix A * Matrix B will return vals for a Matrix C
	Matrix operator * (const Matrix &B);

private:
	int rows_;
        int cols_;
        int **vals_;
};
#endif
