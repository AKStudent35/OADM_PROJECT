#include <iostream>
#include "IterationObject.h"
#include <math.h>

void Object::SetDefaultState()
{
	Range1 = 0;
	Range2 = Radius * sqrtf(2);

	aRange1 = 0;
	aRange2 = 45;

	IterationCounter = 0;
}

void Object::SetDefaultState(float _alpha, float _beta, float _radius)
{
	Alpha = _alpha;
	Beta = _beta;
	Radius = _radius;
	
	Range1 = 0;
	Range2 = _radius * sqrtf(2);

	aRange1 = 0;
	aRange2 = 45;

	IterationCounter = 0;
}

float Object::CalculateB(float _a)
{
	float buff;
	buff = sqrtf(Radius * Radius * 4 - _a * _a);

	return (buff -_a)/2;
}

float Object::CalculateA(float _angle)
{
	return 2 * Radius * sinf(_angle * 3.14 / 180);
}

void Object::PrintWarning()
{
	std::cout << "this optimal sollution makes no sense" << std::endl << "there is no sense for doing anything if there is no income" << std::endl << "that makes a = 0 and b = 0" << std::endl;
	std::cout << std::endl << std::endl;
}
