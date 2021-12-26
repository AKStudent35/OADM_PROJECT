#include <iostream>
#include "FibonnaciManager.h"

int main()
{
	FIBMAN::Manager _manager;
	_manager.FirstIteration();

	int counter = 0;
	while(1){
		_manager.Iterate();
		counter++;
		if (_manager.Difference < 0.01) {
			break;
		}

	}
	_manager.PrintResult();
	std::cout << "it took " << counter << " iterations" << std::endl;

	return 0;
}
