#include <iostream>
#include "Fib.h"



void Fib4a::PrintResult()
{
	std::cout << "Result obtained with fibonacci method for '4a' cutting method" << std::endl;
	if (Result > 0) {
		std::cout << "a= " << Range1 << std::endl;
		std::cout << "b= " << CalculateB(Range1) << std::endl;
		std::cout << "result= " << Result << std::endl;
		std::cout << "it took " << IterationCounter << " iterations to obtain result" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}
	else {
		PrintWarning();
	}
}

void Fib4a::FirstIteration(float _alpha,float  _beta,float _radius)
{
	SetDefaultState(_alpha,_beta,_radius);
}

void Fib4a::Iterate()
{
	float _result1;
	float _result2;

	float A1;
	float A2;

	while (1) {

		A1 = ((Range2 - Range1) / 3)+Range1;
		A2 = ((Range2 - Range1) * 2 / 3)+Range1;

		
		if (Range2-Range1< 0.01) {
			Result = ReturnResult(A1);
			PrintResult();
			break;
		}

		_result1 = ReturnResult(A1);
		_result2 = ReturnResult(A2);


		//std::cout << _result1 << std::endl << _result2 << std::endl << A1 << std::endl << A2 << std::endl;

		if (_result1 > _result2) {
			Range2 = A2;
		}
		else {
			Range1 = A1;
		}
	}
}

float Fib4a::ReturnResult(float _a)
{
	return  _a *_a * Alpha * sqrtf(4*Radius*Radius-_a*_a)*0.5  - _a * _a * _a * Alpha * 0.5 - 4 * Beta * sqrtf(4 * Radius * Radius - _a * _a);
}





void Fib8a::PrintResult()
{
	std::cout << "Result obtained with fibonacci method for '8a' cutting method" << std::endl;
	if (Result > 0) {
		std::cout << "a= " << Range1 << std::endl;
		std::cout << "b= " << CalculateB(Range1) << std::endl;
		std::cout << "result= " << Result << std::endl;
		std::cout << "it took " << IterationCounter << " iterations to obtain result" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}
	else {
		PrintWarning();
	}

}

void Fib8a::FirstIteration(float _alpha, float  _beta, float _radius)
{
	SetDefaultState(_alpha, _beta, _radius);
}

void Fib8a::Iterate()
{
	float _result1;
	float _result2;

	float A1;
	float A2;

	while (1) {

		A1 = ((Range2 - Range1) / 3) + Range1;
		A2 = ((Range2 - Range1) * 2 / 3) + Range1;


		if (Range2 - Range1 < 0.01) {
			Result = ReturnResult(A1);
			PrintResult();
			break;
		}

		_result1 = ReturnResult(A1);
		_result2 = ReturnResult(A2);


		//std::cout << _result1 << std::endl << _result2 << std::endl << A1 << std::endl << A2 << std::endl;

		if (_result1 > _result2) {
			Range2 = A2;
		}
		else {
			Range1 = A1;
		}
	}
}

float Fib8a::ReturnResult(float _a)
{
	float buff = _a * _a * Alpha * sqrtf(4 * Radius * Radius - _a * _a) * 0.5;
	buff -= powf(_a, 3.0) * Alpha * 0.5;
	buff -= 4 * Beta * _a;
	buff -= 4 * Beta * sqrtf(4 * Radius * Radius - _a * _a);
	return  buff;
}






void Fib4angle::Iterate()
{
	float _result1;
	float _result2;

	float A1;
	float A2;

	while (1) {

		A1 = ((aRange2 - aRange1) / 3) + aRange1;
		A2 = ((aRange2 - aRange1) * 2 / 3) + aRange1;


		if (aRange2 - aRange1 < 0.01) {
			Result = ReturnResult(A1);
			PrintResult();
			break;
		}

		_result1 = ReturnResult(A1);
		_result2 = ReturnResult(A2);


		//std::cout << _result1 << std::endl << _result2 << std::endl << A1 << std::endl << A2 << std::endl;

		if (_result1 > _result2) {
			aRange2 = A2;
		}
		else {
			aRange1 = A1;
		}
	}
}

void Fib4angle::FirstIteration(float _alpha, float  _beta, float _radius)
{
	SetDefaultState(_alpha, _beta, _radius);
}

void Fib4angle::PrintResult()
{
	std::cout << "Result obtained with fibonacci method for '4angle' cutting method" << std::endl;
	if (Result > 0) {
		std::cout << "a= " << CalculateA(aRange1) << std::endl;
		std::cout << "b= " << CalculateB(CalculateA(aRange1)) << std::endl;
		std::cout << "optimal angle is equal to " << aRange1 << std::endl;
		std::cout << "result= " << Result << std::endl;
		std::cout << "it took " << IterationCounter << " iterations to obtain result" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}
	else {
		PrintWarning();
	}
}

float Fib4angle::ReturnResult(float _angle)
{
	_angle = _angle * 3.14 / 180;
	float buff = 4 * powf(Radius, 3) * sinf(_angle) * sinf(_angle) * cosf(_angle) * Alpha;
	buff -= 4 * Alpha * powf(Radius, 3) * sinf(_angle) * sinf(_angle) * sinf(_angle);
	buff -= 8 * Beta * Radius * cosf(_angle);

	return buff;
}





void Fib8angle::Iterate()
{
	float _result1;
	float _result2;

	float A1;
	float A2;

	while (1) {

		A1 = ((aRange2 - aRange1) / 3) + aRange1;
		A2 = ((aRange2 - aRange1) * 2 / 3) + aRange1;


		if (aRange2 - aRange1 < 0.01) {
			Result = ReturnResult(A1);
			PrintResult();
			break;
		}

		_result1 = ReturnResult(A1);
		_result2 = ReturnResult(A2);


		//std::cout << _result1 << std::endl << _result2 << std::endl << A1 << std::endl << A2 << std::endl;

		if (_result1 > _result2) {
			aRange2 = A2;
		}
		else {
			aRange1 = A1;
		}
	}
}

void Fib8angle::FirstIteration(float _alpha, float  _beta, float _radius)
{
	SetDefaultState(_alpha, _beta, _radius);
}

void Fib8angle::PrintResult()
{
	std::cout << "Result obtained with fibonacci method for '8angle' cutting method" << std::endl;
	if (Result > 0) {
		std::cout << "a= " << CalculateA(aRange1) << std::endl;
		std::cout << "b= " << CalculateB(CalculateA(aRange1)) << std::endl;
		std::cout << "optimal angle is equal to " << aRange1 << std::endl;
		std::cout << "result= " << Result << std::endl;
		std::cout << "it took " << IterationCounter << " iterations to obtain result" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}
	else {
		PrintWarning();
	}
}

float Fib8angle::ReturnResult(float _angle)
{
	_angle = _angle * 3.14 / 180;
	float buff = 4 * powf(Radius,3)*sinf(_angle)* sinf(_angle)*cosf(_angle)*Alpha;
	buff -= 4 * Alpha *powf(Radius, 3)* sinf(_angle)* sinf(_angle)* sinf(_angle);
	buff -= 8 *Beta*Radius * sinf(_angle);
	buff -= 8 *Beta*Radius * cosf(_angle);

	return buff;
}
