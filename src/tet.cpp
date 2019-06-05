#include "tet.h"

Tetrahedron::Tetrahedron(const std::string& fname) : Shape(fname, 3)
{
	std::cout<<"Constuctor for Tetrahedron sub-class."<<"\n";
}

double Tetrahedron::area() const
{
	std::cout<<"Area of a Tetrahedron is undefined, returning 0."<<"\n";
	return 0;
}

double Tetrahedron::volume() const
{
	// Place-holder
	std::cout<<"Volume calculation occurs ..."<<"\n";
	return 1.0;
}
