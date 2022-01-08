#include <iostream>
#include"Fib.h"
#include"Grad.h"

int main()
{
	float a, b, c;

	std::cout << "put price alpha" << std::endl;
	std::cin >> a;
	std::cout << "put cost beta" << std::endl;
	std::cin >> b;
	std::cout << "put radius" << std::endl;
	std::cin >> c;


 
	Fib4a _fib4a;
	_fib4a.FirstIteration(a, b, c);
	_fib4a.Iterate();

	Fib8a _fib8a;
	_fib8a.FirstIteration(a, b, c);
	_fib8a.Iterate();

	Grad4a _grad4a;
	_grad4a.FirstIteration(a, b, c);
	_grad4a.Iterate();


	//r10 a5b1
	Grad8a _grad8a;
	_grad8a.FirstIteration(a, b, c);
	_grad8a.Iterate();


	Fib4angle _fib4angle;
	_fib4angle.FirstIteration(a, b, c);
	_fib4angle.Iterate();

	Fib8angle _fib8angle;
	_fib8angle.FirstIteration(a, b, c);
	_fib8angle.Iterate();

	//Grad4angle _grad4angle;
	//_grad4angle.FirstIteration(a, b, c);
	//_grad4angle.Iterate();

	//Grad8angle _grad8angle;
	//_grad8angle.FirstIteration(a, b, c);
	//_grad8angle.Iterate();

	return 0;
}