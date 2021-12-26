#include <iostream>
#include "FibonnaciManager.h"
#include "GradientManager.h"


int main()
{
	int a;

	std::cout << "if you want to use fibonnaci/contraction method put 1" << std::endl << "if you want to use gradient method put 2" << std::endl;
	std::cin >> a;
	if (a == 1) {
		FIBMAN::Manager _FIBmanager;
		_FIBmanager.FirstIteration();

		int counter = 0;
		while (1) {
			_FIBmanager.Iterate();
			counter++;
			if (_FIBmanager.Difference < 0.01) {
				break;
			}

		}
		_FIBmanager.PrintResult();
		std::cout << "it took " << counter << " iterations" << std::endl;
	}
	if (a == 2){
		GRADMAN::Manager _gradManager;
		_gradManager.FirstIteration();

		int counter = 0;

		while (1) {
			counter++;
			_gradManager.Iterate(counter);
			//std::cout << _gradManager._iterationObject.GradValue << std::endl;
			if (_gradManager._iterationObject.GradValue * _gradManager._iterationObject.GradValue < 0.01) { break; }
		}
		_gradManager.PrintResult();

	}

	return 0;
}
