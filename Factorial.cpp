#include <iostream>

/* This program calculates the factorial 
 * of a number and returns the result*/

int main() {
	int x={}; //Initialize input variable x	
	std::cout << "Please enter a positive integer: ";
	std::cin >> x;	

	int y={1}; //Initialize ouput variable y
	int z={2}; //Start at lowest value of factorial
	while (z<=x)
		{
		y = y*z;
		++z;
		}

	std::cout << "The factorial of " << x << " is " << y << '\n';
	return 0;
}
