#include <iostream>
#include <math.h>
#include "GradientManager.h"

void PrintData(GRAD::IterationObject _iterationObject) {
	std::cout << "A is equal to " << _iterationObject.A << std::endl;
	std::cout << "B is equal to " << _iterationObject.B << std::endl;

	std::cout << "Radius is equal to " << _iterationObject.Radius << std::endl;

	std::cout << "Apha is equal to " << _iterationObject.Alpha << std::endl;
	std::cout << "Beta is equal to " << _iterationObject.Beta << std::endl;

	std::cout << "Factor is equal to " << _iterationObject.Factor << std::endl;
	std::cout << "Grad value is equal to " << _iterationObject.GradValue << std::endl;
}

void SetValues(GRAD::IterationObject& _iterationObject) {
	_iterationObject.Radius = _iterationObject.ReturnRadius();
	
	_iterationObject.A = 1;
	_iterationObject.B = _iterationObject.CalculateB();
	
	_iterationObject.Alpha = _iterationObject.ReturnAlpha();
	_iterationObject.Beta  = _iterationObject.ReturnBeta();

	_iterationObject.Factor = 0.1;
	_iterationObject.GradValue = _iterationObject.ReturnGradValue();

	PrintData(_iterationObject);
}

void GRADMAN::Manager::FirstIteration() {
	SetValues(_iterationObject);
}

void GRADMAN::Manager::Iterate(int &counter) {

	if (counter == 10) {
		_iterationObject.ChangeFactor(1);
		counter = 0;
	}

	float buff;

	buff = _iterationObject.A;
	buff += _iterationObject.Factor * _iterationObject.ReturnGradValue(buff);
	if (_iterationObject.ReturnGradValue(buff) < 0) {
		_iterationObject.ChangeFactor(-1);
		counter = 0;
	}
	else {
		_iterationObject.GradValue = _iterationObject.ReturnGradValue();
		_iterationObject.A += _iterationObject.Factor * _iterationObject.GradValue;
	}
}

void GRADMAN::Manager::PrintResult() {
	std::cout << "A is equal to      " << _iterationObject.A << std::endl;
	std::cout << "B is equal to      " << _iterationObject.CalculateB() << std::endl;
	std::cout << "income is equal to " << _iterationObject.ReturnResult();

}