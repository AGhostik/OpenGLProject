#pragma once
#include <Windows.h>
#include <gl/GL.h>

class Point
{
public:
	GLint x;
	GLint y;
	Point() = default;
	Point(GLint xValue, GLint yValue);
	~Point();
};

