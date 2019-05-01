#include <iostream>
#include "matrix.h"

// Constructor, initialize array of zeros.
Matrix::Matrix(int rows, int cols)
{
	rows_ = rows;
	cols_ = cols;
		
        vals_ = new int*[rows];
        for (int rid=0; rid<rows_; ++rid)
        {
        	vals_[rid] = new int[cols_];
                for (int cid=0; cid<cols_; ++cid)
                	vals_[rid][cid] = 0;
        }
}	

// Implement getrows
int Matrix::getcols() const {return cols_;}

// Implement getcols
int Matrix::getrows() const {return rows_;}

// Allow user defined set, where will loop through values of Matrix
void Matrix::setbyusr()
{
	for (int rid=0; rid<rows_; ++rid)
	{
		for (int cid=0; cid<cols_; ++cid)
		{
			std::cout<<"Enter entry ["<<rid<<","<<cid<<"]: ";
			std::cin>>vals_[rid][cid];
		}
	}				
}

// Print Matrix for visualization	
void Matrix::print()
{
	for (int rid=0; rid<rows_; ++rid)
	{
		for (int cid=0; cid<cols_; ++cid)
                   	std::cout<<vals_[rid][cid]<<" ";
		std::cout<<"\n";
	}
}

// Destructor to handle dynamic array
Matrix::~Matrix()
{
	for (int rid=0; rid<rows_; ++rid)
		delete[] vals_[rid];
	delete[] vals_;
}

// Implement overload + operator
Matrix Matrix::operator + (const Matrix &B)
{
	Matrix temp{rows_, cols_}; //Set it to size of A aribrarily

	if ((rows_==B.Matrix::getrows()) && (cols_==B.Matrix::getcols())) //If A and B are same size
	{
               	for (int rid=0; rid<rows_; ++rid)
		{
                       	for (int cid=0; cid<cols_; ++cid)
				temp.vals_[rid][cid] = vals_[rid][cid] + B.vals_[rid][cid];
		}
	}
	else //If A and B are different sizes
		std::cout<<"Operation not allowed rows and cols must match.\n";
	return temp;
}	

// Implement overload * operator
Matrix Matrix::operator * (const Matrix &B)
{
	Matrix temp{rows_,B.Matrix::getcols()};

	if (cols_==B.Matrix::getrows())
	{
		for (int rid=0; rid<rows_; ++rid)
		{	
			for (int cid=0; cid<cols_; ++cid)
			{
				for (int dloc=0; dloc<cols_; ++dloc)
					temp.vals_[rid][cid]+=vals_[rid][dloc] * B.vals_[dloc][cid];
			}
		}
	}
	else
		std::cout<<"Operation not allowed cols of A == rows of B.\n";		
	return temp;
}

