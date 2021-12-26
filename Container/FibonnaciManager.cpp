#include <iostream>
#include<math.h>
#include"FibonnaciManager.h"

float ReturnRange2(float R) {
	R *= 2;
	return R * sqrtf(2) * 0.5;
}

void SetVariables(FIB::IterationObject& _iterationObject) {
	_iterationObject.Alpha = _iterationObject.ReturnAlpha();
	_iterationObject.Beta = _iterationObject.ReturnBeta();
	
	_iterationObject.Radius = _iterationObject.ReturnRadius();

	_iterationObject.A = 1;
	_iterationObject.B = _iterationObject.CalculateB(_iterationObject.A);

	_iterationObject.Range1 = 0;
	_iterationObject.Range2 = ReturnRange2(_iterationObject.Radius);

}

void PrintData(FIB::IterationObject _iterationObject) {
	std::cout << "A is equal to " << _iterationObject.A << std::endl;
	std::cout << "B is equal to " << _iterationObject.B << std::endl;
	
	std::cout << "Radius is equal to " << _iterationObject.Radius << std::endl;

	std::cout << "Apha is equal to " << _iterationObject.Alpha << std::endl;
	std::cout << "Beta is equal to " << _iterationObject.Beta << std::endl;

	std::cout << "Range 1 is equal to " << _iterationObject.Range1 << std::endl;
	std::cout << "Range 2 is equal to " << _iterationObject.Range2 << std::endl;

}

float FIBMAN::Manager::ReturnDifference() {
	return _iterationObject.Range2 - _iterationObject.Range1;
}

void FIBMAN::Manager::FirstIteration() {
	SetVariables(_iterationObject);
	PrintData(_iterationObject);

	Iterate();

}

void FIBMAN::Manager::Iterate() {

	float _result1;
	float _result2;

	float A1;
	float A2;

	A1 = (_iterationObject.Range2 - _iterationObject.Range1) / 3 + _iterationObject.Range1;
	A2 = ((_iterationObject.Range2 - _iterationObject.Range1)*2) / 3 + _iterationObject.Range1;

	_result1 = _iterationObject.ReturnResult(A1);
	_result2 = _iterationObject.ReturnResult(A2);


	//std::cout << _result1 << std::endl << _result2 << std::endl << A1 << std::endl << A2 << std::endl;


	if (_result1 > _result2) {
		_iterationObject.Range2 = A2;
	}
	else {
		_iterationObject.Range1 = A1;
	}

	Difference=ReturnDifference();

}

void FIBMAN::Manager::PrintResult() {

	std::cout << std::endl << std::endl << std::endl << "printing result" << std::endl;
	std::cout << "Range 1 is equal to " << _iterationObject.Range1 << std::endl;
	std::cout << "Range 2 is equal to " << _iterationObject.Range2 << std::endl;

	std::cout << "A is equal to " << _iterationObject.Range1 << std::endl;
	std::cout << "B is equal to " << _iterationObject.CalculateB(_iterationObject.Range1) << std::endl;

	std::cout << "income is equal to " << _iterationObject.ReturnResult(_iterationObject.Range1) << std::endl;
}
