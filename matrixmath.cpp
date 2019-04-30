#include <iostream>

class Matrix
{
public:
	// Constructor, initialize array of zeros.
	Matrix(int rows, int cols)
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
	
	// Allow user defined set, where will loop through values of matrix
	void setbyusr()
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

	//void set(int** valstoset) {vals=valstoset;}

	int getrows() const {return rows_;}

	int getcols() const {return cols_;}

	// Print matrix for visualization	
	void print()
	{
		for (int rid=0; rid<rows_; ++rid)
		{
			for (int cid=0; cid<cols_; ++cid)
                     	std::cout<<vals_[rid][cid]<<" ";
		std::cout<<"\n";
		}
	}

	// Destructor to handle dynamic array
	~Matrix()
	{
		for (int rid=0; rid<rows_; ++rid)
			delete[] vals_[rid];
		delete[] vals_;
	}

	// Overload + opperator so that Matrix A + Matrix B will return vals for a Matrix C
	Matrix operator + (const Matrix &B)
	{
		Matrix temp{rows_, cols_}; //Set it to size of A aribrarily

		if ((rows_==B.getrows()) && (cols_==B.getcols())) //If A and B are same size
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

	// Overload * operator so that Matrix A * Matrix B will return vals for a Matrix C
	Matrix operator * (const Matrix &B)
	{
		Matrix temp{rows_,B.getcols()};

		if (cols_==B.getrows())
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

private:
	int rows_;
        int cols_;
        int **vals_;

};

int main()
{
	// Initialize A
	std::cout<<"Rows of A: ";
	int arows;
	std::cin>>arows;
	
	std::cout<<"Columns of A: ";
	int acols;
	std::cin>>acols;

	Matrix A {arows,acols};
	A.setbyusr();
	A.print();

	// Initialize B
	std::cout<<"Rows of B: ";
	int brows;
	std::cin>>brows;
	
	std::cout<<"Columns of B: ";
	int bcols;
	std::cin>>bcols;
	
	Matrix B {brows,bcols};
	B.setbyusr();
	B.print();

	// Overload + operator	
	
	// Doesnt work
	//Matrix C{2,2};
	//C=A+B;	
	//C.print();
	
	// Does work
	Matrix C=A+B;
	C.print();

	// Overload * operator - Matrix * Matrix
	Matrix D=A * B;
	D.print();
}
