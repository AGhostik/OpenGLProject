#include "Math.h"

int Math::Random(int max) {
	return rand() % max;
}

float Math::Random(float from, float to) {
	return from + ( rand() / (RAND_MAX / (to - from)) );
}

double Math::Random(double from, double to) {
	return from + ( rand() / (RAND_MAX / (to - from)) );
}

Math::Math()
{
}

Math::~Math()
{
}
