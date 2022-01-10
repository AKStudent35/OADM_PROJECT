#include <iostream>
#include"Fib.h"
#include"Grad.h"

int main()
{
	int state;
	std::cout << "if you would like to try regural version of program put 0" << "if bonus version put 1" << std::endl;
	std::cin >> state;
	
	float a, b, R, n;

	while (state == 0) {

		std::cout << "put price alpha" << std::endl;
		std::cin >> a;
		std::cout << "put cost beta" << std::endl;
		std::cin >> b;
		std::cout << "put radius" << std::endl;
		std::cin >> R;



		Fib4a *_fib4a=new Fib4a;
		_fib4a->FirstIteration(a, b, R);
		_fib4a->Iterate();
		delete _fib4a;

		Fib8a* _fib8a = new Fib8a;
		_fib8a->FirstIteration(a, b, R);
		_fib8a->Iterate();
		delete _fib8a;

		Grad4a* _grad4a=new Grad4a;
		_grad4a->FirstIteration(a, b, R);
		_grad4a->Iterate();
		delete _grad4a;


		Grad8a* _grad8a=new Grad8a;
		_grad8a->FirstIteration(a, b, R);
		_grad8a->Iterate();
		delete _grad8a;


		Fib4angle* _fib4angle=new Fib4angle;
		_fib4angle->FirstIteration(a, b, R);
		_fib4angle->Iterate();
		delete _fib4angle;


		Fib8angle* _fib8angle=new Fib8angle;
		_fib8angle->FirstIteration(a, b, R);
		_fib8angle->Iterate();
		delete _fib8angle;


		Grad4angle* _grad4angle= new Grad4angle;
		_grad4angle->FirstIteration(a, b, R);
		_grad4angle->Iterate();
		delete _grad4angle;


		Grad8angle* _grad8angle= new Grad8angle;
		_grad8angle->FirstIteration(a, b, R);
		_grad8angle->Iterate();
		delete _grad8angle;


		std::cout << "if you want to make more iterations put 0  if not put 2" << std::endl;
		std::cin >> state;
	}

	while (state == 1) {

		std::cout << "put price alpha" << std::endl;
		std::cin >> a;
		std::cout << "put cost beta" << std::endl;
		std::cin >> b;
		std::cout << "put radius" << std::endl;
		std::cin >> R;
		std::cout << "put number of shapes you would like to check" << std::endl;
		std::cin >> n;
		if (n < 2)break;

		for (int i = 3; i < n+3; i++) {
			BonusFib8angle *_Bonusfib8angle=new BonusFib8angle;
			_Bonusfib8angle->FirstIteration(a, b, R);
			std::cout << "for " << i << " corner shape" << std::endl;
			_Bonusfib8angle->Iterate(i);
			delete _Bonusfib8angle;
		}
		std::cout << "if you want to make more iterations put 0  if not put 2" << std::endl;
		std::cin >> state;
	}
	return 0;
}