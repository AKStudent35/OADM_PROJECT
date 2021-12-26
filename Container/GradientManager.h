#include <iostream>
#include "Gradient.h"

namespace GRADMAN {
	class Manager {
	public:
		GRAD::IterationObject _iterationObject;

		void FirstIteration();

		void Iterate(int &counter);

		void PrintResult();
	};
}