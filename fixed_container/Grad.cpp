#include<iostream>
#include<math.h>
#include"Grad.h"

void Grad4a::FirstIteration(float _alpha, float  _beta, float _radius) {
	SetDefaultState(_alpha, _beta, _radius);
	GradFactor = 0.1f;
}

float Grad4a::StopCondition() {
	float buff = Range1;
	return powf(buff - buff+ GradFactor * GradValue,2);
}

void Grad4a::Iterate() {
	int a = 0;
	Range1 += 0.01;
	while (1) {
		IterationCounter++;
		a++;

		SingleIteration(a);
		
		//std::cout << _gradManager._iterationObject.GradValue << std::endl;
		if (StopCondition() < 0.0001) { break; }
	}
	Result = ReturnResult(Range1);
	PrintResult();
}

void Grad4a::SingleIteration(int a) {
	if (a%10 == 0) {
		ChangeFactor(1);
		a = 0;
	}

	float buff;

	buff = Range1;
	buff += GradFactor * ReturnGradValue(buff);
	if (ReturnGradValue(buff) < 0 || buff >= Range2) {
		ChangeFactor(-1);
		a = 0;
	}
	else {
		GradValue = ReturnGradValue(Range1);
		Range1+= GradFactor * GradValue;
	}
	//std::cout << Range1 << std::endl << GradValue << std::endl;
}

void Grad4a::PrintResult()
{
	std::cout << "Result obtained with Gradient method for '4a' cutting method" << std::endl;
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

void Grad4a::ChangeFactor(int k)
{
	if (k < 0) {
		GradFactor /= 2;
	}
	if (k > 0) {
		GradFactor *= 2;
	}

}

float Grad4a::ReturnResult(float _a)
{
	return  _a * _a * Alpha * sqrtf(4 * Radius * Radius - _a * _a) * 0.5 - _a * _a * _a * Alpha * 0.5 - 4 * Beta * sqrtf(4 * Radius * Radius - _a * _a);
}

float Grad4a::ReturnGradValue(float X)
{
	float buff;

	//std::cout << A << std::endl;


	buff = Alpha * X * sqrtf(4 * Radius * Radius - X* X) - (Alpha * X* X* X) / (sqrtf(4 * Radius * Radius - X* X) * 2) - 1.5 * Alpha * X* X + (4 * Beta * X) / (sqrtf(4 * Radius * Radius -X* X));
	//std::cout << buff << std::endl;
	return buff;
}





void Grad8a::FirstIteration(float _alpha, float  _beta, float _radius) {
	SetDefaultState(_alpha, _beta, _radius);
	GradFactor = 0.1f;
}

float Grad8a::StopCondition() {
	float buff = Range1;
	return powf(buff - buff + GradFactor * GradValue, 2);
}

void Grad8a::Iterate() {
	int a = 0;
	Range1 += 0.01;

	while (1){
		if (ReturnGradValue(Range1) <= 0) {
			Range1 += 0.03;
		}
		else {
			break;
		}
	}

	while (1) {
		IterationCounter++;
		a++;

		SingleIteration(a);
		//std::cout << GradValue << std::endl;
		if (StopCondition() < 0.0001) { break; }
	}
	Result = ReturnResult(Range1);
	PrintResult();
}

void Grad8a::SingleIteration(int a) {
	if (a % 10 == 0) {
		ChangeFactor(1);
		a = 0;
	}

	float buff;

	buff = Range1;
	buff += GradFactor * ReturnGradValue(buff);
	if (ReturnGradValue(buff) < 0||buff>=Range2) {
		ChangeFactor(-1);
		a = 0;
	}
	else {
		GradValue = ReturnGradValue(Range1);
		Range1 += GradFactor * GradValue;
	}
	//std::cout << Range1 << std::endl << GradValue << std::endl;
}

void Grad8a::PrintResult()
{
	std::cout << "Result obtained with Gradient method for '8a' cutting method" << std::endl;
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

void Grad8a::ChangeFactor(int k)
{
	if (k < 0) {
		GradFactor /= 2;
	}
	if (k > 0) {
		GradFactor *= 2;
	}

}

float Grad8a::ReturnResult(float _a)
{
	return  _a * _a * Alpha * sqrtf(4 * Radius * Radius - _a * _a) * 0.5 - _a * _a * _a * Alpha * 0.5 - 4*Beta*_a - 4 * Beta * sqrtf(4 * Radius * Radius - _a * _a);
}

float Grad8a::ReturnGradValue(float X)
{
	float buff;

	//std::cout << A << std::endl;


	buff = Alpha * X * sqrtf(4 * Radius * Radius - X * X) - (Alpha * X * X * X) / (sqrtf(4 * Radius * Radius - X * X) * 2) - 1.5 * Alpha * X * X - 4*Beta + (4 * Beta * X) / (sqrtf(4 * Radius * Radius - X * X));
	//std::cout << buff << std::endl;
	return buff;
}





void Grad4angle::FirstIteration(float _alpha, float  _beta, float _radius) {
	SetDefaultState(_alpha, _beta, _radius);
	GradFactor = 0.1f;
}

float Grad4angle::StopCondition() {
	float buff = aRange1;
	return powf(buff - buff + GradFactor * ReturnGradValue(buff), 2);
}

void Grad4angle::Iterate() {
	int a = 0;
	aRange1 += 0.01;

	while (1) {
		if (ReturnGradValue(aRange1) <= 0) {
			aRange1 += 0.03;
		}
		else {
			break;
		}
	}

	while (1) {
		IterationCounter++;
		a++;

		SingleIteration(a);
		//std::cout << GradValue << std::endl;
		if (StopCondition() < 0.00001) { break; }
	}
	Result = ReturnResult(CalculateA(aRange1));
	PrintResult();
}

void Grad4angle::SingleIteration(int a) {
	if (a % 10 == 0) {
		ChangeFactor(1);
		a = 0;
	}

	float buff;

	buff = aRange1;
	buff += GradFactor * ReturnGradValue(buff);
	if (ReturnGradValue(buff) < 0 || buff > Range2) {
		ChangeFactor(-1);
		a = 0;
	}
	else {
		GradValue = ReturnGradValue(aRange1);
		aRange1 += GradFactor * GradValue;
	}
	//std::cout << Range1 << std::endl << GradValue << std::endl;
}

void Grad4angle::ChangeFactor(int k)
{
	if (k < 0) {
		GradFactor /= 2;
	}
	if (k > 0) {
		GradFactor *= 2;
	}

}

void Grad4angle::PrintResult()
{
	std::cout << "Result obtained with Gradient method for '4angle' cutting method" << std::endl;
	if (Result > 0) {
		std::cout << "a= " << CalculateA(aRange1) << std::endl;
		std::cout << "b= " << CalculateB(CalculateA(aRange1)) << std::endl;
		std::cout << "optimal angle is equal to " << aRange1 << std::endl;
		std::cout << "result= " << ReturnResult(aRange1) << std::endl;
		std::cout << "it took " << IterationCounter << " iterations to obtain result" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}
	else {
		PrintWarning();
	}
}

float Grad4angle::ReturnResult(float _angle)
{
	_angle = _angle * 3.14 / 180;
	float buff = 4 * powf(Radius, 3) * sinf(_angle) * sinf(_angle) * cosf(_angle) * Alpha;
	buff -= 4 * Alpha * powf(Radius, 3) * sinf(_angle) * sinf(_angle) * sinf(_angle);
	buff -= 8 * Beta * Radius * cosf(_angle);

	return buff;
}

float Grad4angle::ReturnGradValue(float a)
{
	float buff;
	float _a = a * 3.14 / 180;

	//std::cout << A << std::endl;
	buff = 3 * cosf(_a) * cosf(_a) - 1;
	buff -= 1.5 * sinf(_a * 2);
	buff *= Alpha * powf(Radius, 2);
	buff += 2 * Beta;
	buff *= 4 * Radius * sinf(_a);
	//std::cout << buff << std::endl;
	return buff;
}








void Grad8angle::FirstIteration(float _alpha, float  _beta, float _radius) {
	SetDefaultState(_alpha, _beta, _radius);
	GradFactor = 0.1f;
}

float Grad8angle::StopCondition() {
	float buff = aRange1;
	return powf(buff - buff + GradFactor * ReturnGradValue(buff), 2);
}

void Grad8angle::Iterate() {
	int a = 0;
	aRange1 += 0.01;

	while (1) {
		if (ReturnGradValue(aRange1) <= 0) {
			aRange1 += 0.03;
		}
		else {
			break;
		}
	}

	while (1) {
		IterationCounter++;
		a++;

		SingleIteration(a);
		//std::cout << GradValue << std::endl;
		if (StopCondition() < 0.00001) { break; }
	}
	Result = ReturnResult(CalculateA(aRange1));
	PrintResult();
}

void Grad8angle::SingleIteration(int a) {
	if (a % 10 == 0) {
		ChangeFactor(1);
		a = 0;
	}

	float buff;

	buff =  aRange1;
	buff += GradFactor * ReturnGradValue(buff);
	if (ReturnGradValue(buff) < 0 || buff>Range2) {
		ChangeFactor(-1);
		a = 0;
	}
	else {
		GradValue = ReturnGradValue(aRange1);
		aRange1 += GradFactor * GradValue;
	}
	//std::cout << Range1 << std::endl << GradValue << std::endl;
}

void Grad8angle::ChangeFactor(int k)
{
	if (k < 0) {
		GradFactor /= 1.1;
	}
	if (k > 0) {
		GradFactor *= 1.1;
	}

}

void Grad8angle::PrintResult()
{
	std::cout << "Result obtained with Gradient method for '8angle' cutting method" << std::endl;
	if (Result > 0) {
		std::cout << "a= " << CalculateA(aRange1) << std::endl;
		std::cout << "b= " << CalculateB(CalculateA(aRange1)) << std::endl;
		std::cout << "optimal angle is equal to " << aRange1 << std::endl;
		std::cout << "result= " << ReturnResult(aRange1) << std::endl;
		std::cout << "it took " << IterationCounter << " iterations to obtain result" << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}
	else {
		PrintWarning();
	}
}

float Grad8angle::ReturnResult(float _angle)
{
	_angle = _angle * 3.14 / 180;
	float buff = 4 * powf(Radius, 3) * sinf(_angle) * sinf(_angle) * cosf(_angle) * Alpha;
	buff -= 4 * Alpha * powf(Radius, 3) * sinf(_angle) * sinf(_angle) * sinf(_angle);
	buff -= 8 * Beta * Radius * sinf(_angle);
	buff -= 8 * Beta * Radius * cosf(_angle);

	return buff;
}

float Grad8angle::ReturnGradValue(float a)
{
	float buff;
	float _a = a * 3.14 / 180;

	//std::cout << A << std::endl;
	buff = cosf(_a) * 3 * Alpha * powf(Radius, 2) * sinf(_a) * sinf(_a);
	buff += cosf(_a) * 2 * Beta;
	buff += sinf(_a) * sinf(_a) * sinf(_a) * Alpha * powf(Radius, 2);
	buff -= 2 * Alpha * powf(Radius, 2) * sinf(_a) * cosf(_a) * cosf(_a);
	buff -= 2 * Beta * sinf(_a);
	buff *= -4 * Radius;
	//std::cout << buff << std::endl;
	return buff;
}
