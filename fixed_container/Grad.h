#include <iostream>
#include "IterationObject.h"

class Grad4a:public Object{
public:
	
	void FirstIteration(float _alpha, float  _beta, float _radius);
	void Iterate();
	void SingleIteration(int a);
	void ChangeFactor(int a);
	void PrintResult();

	float StopCondition();
	float ReturnResult(float _a);
	float ReturnGradValue(float X);
};

class Grad8a :public Object{
public:
	void FirstIteration(float _alpha, float  _beta, float _radius);
	void Iterate();
	void SingleIteration(int a);
	void ChangeFactor(int a);
	void PrintResult();

	float StopCondition();
	float ReturnResult(float _a);
	float ReturnGradValue(float X);
};

class Grad4angle :public Object {
public:
	void FirstIteration(float _alpha, float  _beta, float _radius);
	void Iterate();
	void SingleIteration(int a);
	void ChangeFactor(int a);
	void PrintResult();

	float StopCondition();
	float ReturnResult(float _a);
	float ReturnGradValue(float X);
};

class Grad8angle :public Object {
public:
	void FirstIteration(float _alpha, float  _beta, float _radius);
	void Iterate();
	void SingleIteration(int a);
	void ChangeFactor(int a);
	void PrintResult();

	float StopCondition();
	float ReturnResult(float _a);
	float ReturnGradValue(float X);
};