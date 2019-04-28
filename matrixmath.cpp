#include <iostream>

class Matrix
{
public:

	int vals[2][2];
	int rows = 2;
	int cols = 2;

	
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

	void add(Matrix &A, Matrix &B)
	{
		for (int rid=0; rid<rows; ++rid)
		{
			for (int cid=0; cid<cols; ++cid)
				vals[rid][cid] = A.vals[rid][cid] + B.vals[rid][cid];
		}
	}

};




int main()
{
	Matrix A;
	A.set();
	A.print();

	Matrix B;
	B.set();
	B.print();

	Matrix C;
	C.add(A,B);
	C.print();
}
