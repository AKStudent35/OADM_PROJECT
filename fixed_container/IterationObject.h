#pragma once

class Object {
public:
	float Alpha;
	float Beta;
	float Radius;
	float Result;
	int IterationCounter;

	
	float Range1;
	float Range2;

	float aRange1;
	float aRange2;

	float GradFactor;
	float GradValue;

	void SetDefaultState();
	void SetDefaultState(float _alpha, float _beta, float _radius);
	void PrintWarning();

	float CalculateB(float _a);
	float CalculateA(float _angle);
};