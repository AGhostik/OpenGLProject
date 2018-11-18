#include "Math.h"

double Math::Random(double from, double to)
{
	return from + ( rand() / (RAND_MAX / (to - from)) );
}

float Math::Random(float from, float to)
{
	return from + ( rand() / (RAND_MAX / (to - from)) );
}

int Math::Random(int max)
{
	return rand() % max;
}

Math::Math()
{
}

Math::~Math()
{
}
