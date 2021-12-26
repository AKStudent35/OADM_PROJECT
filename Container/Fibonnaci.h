#pragma once
namespace FIB {
	class IterationObject {
	public:
		float A;
		float B;

		float Radius;

		float Alpha;
		float Beta;

		float Result;

		float Range1;
		float Range2;



		float ReturnAlpha();
		float ReturnBeta();
		float ReturnRadius();
		float ReturnResult(float A);

		float CalculateB(float A);

	};
}