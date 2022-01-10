#include <iostream>
#include "IterationObject.h"

class Fib4a:public Object {
public:

	void FirstIteration(float _alpha,float _beta,float  _radius);
	void Iterate();
	void PrintResult();
	float ReturnResult(float _a);
};

class Fib8a :public Object {
public:

	void FirstIteration(float _alpha, float _beta, float  _radius);
	void Iterate();
	void PrintResult();
	float ReturnResult(float _a);


};

class Fib4angle :public Object {
public:

	void FirstIteration(float _alpha, float _beta, float  _radius);
	void Iterate();
	void PrintResult();
	float ReturnResult(float _angle);


};

class Fib8angle :public Object {
public:

	void FirstIteration(float _alpha, float _beta, float  _radius);
	void Iterate();
	void PrintResult();
	float ReturnResult(float _angle);


};

class BonusFib8angle :public Object {
public:

	void FirstIteration(float _alpha, float _beta, float  _radius);
	void Iterate(int _n);
	void PrintResult();
	float ReturnResult(float _angle,int _n);


};
