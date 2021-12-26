#pragma once
#include "Fibonnaci.h"

namespace FIBMAN {
	class Manager{
	public:

		FIB::IterationObject _iterationObject;

		float Difference;

		void FirstIteration();
		void Iterate();
		void PrintResult();

		float ReturnDifference();
	};
}