#include <iostream>

/* This program calculates the factorial 
 * of a number and returns the result*/

int main() {
	int x; //Initialize input variable x	
	std::cout << "Please enter a positive integer: ";
	std::cin >> x;	

	int y = 1; //Initialize ouput variable y
	for (int z = 1; z <= x; ++z) //Loop from lowest value of z to x
		{
		y = y*z;
		}
	std::cout << "The factorial of " << x << " is " << y << '\n';
}
