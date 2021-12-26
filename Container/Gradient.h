#include <iostream>

namespace GRAD {
	class IterationObject {
	public:
		float A;
		float B;

		float Radius;

		float Alpha;
		float Beta;



		float Factor;
		float GradValue;



		float CalculateB();
		float ReturnGradValue();
		float ReturnGradValue(float A);

		float ReturnRadius();
		float ReturnAlpha();
		float ReturnBeta();
		float ReturnResult();

		void ChangeFactor(int k);

	};
}