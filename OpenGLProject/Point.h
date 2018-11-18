#pragma once
#include "OpenGL.h"

class Point
{
public:
	GLint x;
	GLint y;
	Point() = default;
	Point(GLint xValue, GLint yValue);
	~Point();
};

