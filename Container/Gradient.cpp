#include <iostream>
#include <math.h>
#include"Gradient.h"


float GRAD::IterationObject::CalculateB() {
	float buff = sqrtf(4 * Radius * Radius - A * A) - A;
	buff /= 2;

	return buff;
}

float GRAD::IterationObject::ReturnGradValue()
{
	float buff;

	//std::cout << A << std::endl;


	buff = Alpha * A * sqrtf(4 * Radius * Radius - A * A) - (Alpha * A * A * A) / (sqrtf(4 * Radius * Radius - A * A) * 2) - 1.5 * Alpha * A*A + (4 * Beta * A) / (sqrtf(4 * Radius * Radius - A * A));
	//std::cout << buff << std::endl;
	return buff;
}

float GRAD::IterationObject::ReturnGradValue(float A)
{
	float buff;

	buff = Alpha * A * sqrtf(4 * Radius * Radius - A * A) - (Alpha * A * A * A) / (sqrtf(4 * Radius * Radius - A * A) * 2) - 1.5 * Alpha * A + (4 * Beta * A) / (sqrtf(4 * Radius * Radius - A * A));

	return buff;
}

void  GRAD::IterationObject::ChangeFactor(int k)
{
	if (k < 0) {
		Factor /= 2;
	}
	if (k > 0) {
		Factor *= 2;
	}
}

float GRAD::IterationObject::ReturnAlpha() {
	float buff;
	std::cout << "put alpha" << std::endl;
	std::cin >> buff;
	return buff;
}

float GRAD::IterationObject::ReturnBeta() {
	float buff;
	std::cout << "put beta" << std::endl;
	std::cin >> buff;
	return buff;
}

float GRAD::IterationObject::ReturnResult()
{
	return  A * A * Alpha * sqrtf(4 * Radius * Radius - A * A) * 0.5 - A * A * A * Alpha * 0.5 - 4 * Beta * sqrtf(4 * Radius * Radius - A * A);
}

float GRAD::IterationObject::ReturnRadius() {
	float buff;
	std::cout << "put Radius" << std::endl;
	std::cin >> buff;
	return buff;
}