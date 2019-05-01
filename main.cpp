#include <iostream>
#include "matrix.h"

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
	Matrix C=A+B;
	C.print();

	// Overload * operator - Matrix * Matrix
	Matrix D=A * B;
	D.print();
}
