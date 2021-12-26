#include "Fibonnaci.h"
#include <iostream>
#include <math.h>

float FIB::IterationObject::ReturnAlpha() {
	float buff;
	std::cout << "put alpha" << std::endl;
	std::cin >> buff;
	return buff;
}

float FIB::IterationObject::ReturnBeta() {
	float buff;
	std::cout << "put beta" << std::endl;
	std::cin >> buff;
	return buff;
}

float FIB::IterationObject::ReturnRadius() {
	float buff;
	std::cout << "put Radius" << std::endl;
	std::cin >> buff;
	return buff;
}

float FIB::IterationObject::CalculateB(float A) {
	float buff = sqrtf(4*Radius* Radius -A*A)-A;
	buff /= 2;

	return buff;
}

float FIB::IterationObject::ReturnResult(float A) {
	float buff; 
	buff = A*A*Alpha* sqrtf(4 * Radius * Radius - A * A)*0.5 - A*A*A*Alpha*0.5-4*Beta* sqrtf(4 * Radius * Radius - A * A);

	return buff;
}

