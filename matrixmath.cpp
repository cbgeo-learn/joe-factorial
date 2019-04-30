#include <iostream>

int dotproduct(int* a, int* b, int length)
{
	int dot=0;	
	for (int id=0; id<length; ++id)
		dot+= (a[id]) * (b[id]);
	return dot;		
}


class Matrix
{
private:
	int rows;
	int cols;
	int **vals;

public:
	Matrix( int numrows, int numcols)
	{
		rows = numrows;
		cols = numcols;
		vals = new int*[rows];
		for (int rid=0; rid<rows; ++rid)
		{
			vals[rid] = new int[cols];
			for (int cid=0; cid<cols; ++cid)
				vals[rid][cid] = 0;
		}
	}

	void set()
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
	
	void print()
	{
		for (int rid=0; rid<rows; ++rid)
		{
			for (int cid=0; cid<cols; ++cid)
                     	std::cout<<vals[rid][cid]<<" ";
		std::cout<<"\n"; 
                }
        }

	~Matrix()
	{
		for (int rid=0; rid<rows; ++rid)
			delete[] vals[rid];
		delete[] vals;
	}
/*
	void add(Matrix &A, Matrix &B)
	{
		for (int rid=0; rid<rows; ++rid)
		{
			for (int cid=0; cid<cols; ++cid)
				*vals[rid][cid] = *A.vals[rid][cid] + *B.vals[rid][cid];
		}
	}

	
	Matrix operator + (Matrix &B)
        {
		Matrix temp;
		temp.init();
                for (int rid=0; rid<rows; ++rid)
                {
                        for (int cid=0; cid<cols; ++cid)
                              *temp.vals[rid][cid] = *vals[rid][cid] + *B.vals[rid][cid];
                }
		return temp;
	}	

	Matrix operator * (Matrix &B)
	{
		Matrix temp;
		temp.init();
		for (int rid=0; rid<rows; ++rid)
		{
			for (int cid=0; cid<cols; ++cid)
			{
				for (int lid=0; lid<rows; ++lid)
				{
					*temp.vals[rid][cid]+=*vals[rid][lid] * *B.vals[lid][cid];
				}
			}
		}
		return temp;
	}

*/

};




int main()
{
	// Initialize A
	Matrix A {2,2};
	A.set();
	A.print();

	// Initialize B
	Matrix B {2,2};
	B.set();
	B.print();

/*
	// Use class method to add matrices
	Matrix C;
	C.init();
	C.add(A,B);
	C.print();

	// Overload + operator	
	Matrix D;
	D.init();
	D = A + B;
	D.print();

	// Test dot product
	int a[] = {1,2};
	int b[] = {3,4};

	int c;
	c = dotproduct(a,b,2);
	std::cout<<c<<"\n";

	// Overload * operator
	Matrix E;
	E.init();	
	E = A * B;
	E.print();
	
*/
}

