#include <iostream>

class Matrix
{
public:
	// Constructor, call init to make 2D array and set to set it.
	Matrix(int numrows, int numcols)
	{
		rows = numrows;
		cols = numcols;
		set(init(rows, cols));
	}

	// Make 2D array given rows and cols, and initialize to optional arg value.
	int** init( int numrows, int numcols, int value=0)
	{	
		int **temp;
                temp = new int*[rows];
                for (int rid=0; rid<rows; ++rid)
                {
                        temp[rid] = new int[cols];
                        for (int cid=0; cid<cols; ++cid)
                                temp[rid][cid] = value;
                }
		return temp;
	}	
	
	// Allow user defined set, where will loop through values of matrix
	void setusr()
	{
		for (int rid=0; rid<rows; ++rid)
		{
			for (int cid=0; cid<cols; ++cid)
			{
			std::cout<<"Enter entry ["<<rid<<","<<cid<<"]: ";
			std::cin>>vals[rid][cid];
			}
		}				
	}

	void set(int** valstoset) {vals=valstoset;}

	int getrows() {return rows;}

	int getcols() {return cols;}

	// Print matrix for visualization	
	void print()
	{
		for (int rid=0; rid<rows; ++rid)
		{
			for (int cid=0; cid<cols; ++cid)
                     	std::cout<<vals[rid][cid]<<" ";
		std::cout<<"\n";
		}
	}

	// Destructor to handle dynamic array
	~Matrix()
	{
		for (int rid=0; rid<rows; ++rid)
			delete[] vals[rid];
		delete[] vals;
	}

	// Overload + opperator so that Matrix A + Matrix B will return vals for a Matrix C
	int** operator + (Matrix &B)
	{
		int** temp;
		temp=init(rows,cols);

		if ((rows==B.getrows()) && (cols==B.getcols())) //If A and B are same size
		{
                	for (int rid=0; rid<rows; ++rid)
			{
                        	for (int cid=0; cid<cols; ++cid)
					temp[rid][cid] = vals[rid][cid] + B.vals[rid][cid];
			}
		}
		else //If A and B are different sizes
			std::cout<<"Operation not allowed rows and cols must match";
		return temp;
	}	

	// Overload * operator so that Matrix A * Matrix B will return vals for a Matrix C
	int** operator * (Matrix &B)
	{
		int **temp;
		temp=init(rows,B.getcols());

		if (cols==B.getrows())
		{
		for (int rid=0; rid<rows; ++rid)
		{
			for (int cid=0; cid<cols; ++cid)
			{
				for (int dloc=0; dloc<cols; ++dloc)
					temp[rid][cid]+=vals[rid][dloc] * B.vals[dloc][cid];
			}
		}
		}
		else
			std::cout<<"Operation not allowed cols of A == rows of B";		
		return temp;
	}


private:
	int rows;
        int cols;
        int **vals;

};

int main()
{
	// Initialize A
	Matrix A {2,2};
	A.setusr();
	A.print();

	// Initialize B
	Matrix B {2,2};
	B.setusr();
	B.print();

	// Overload + operator	
	Matrix C {2,2};
	C.set(A + B);
	C.print();

	// Overload * operator - Matrix * Matrix
	Matrix D {2,2}; 
	D.set(A * B);
	D.print();

	// Overload * oeration - Matrix * Vector
}
