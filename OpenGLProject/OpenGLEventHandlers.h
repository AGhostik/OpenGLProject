#pragma once
#include "OpenGL.h"
#include "Point.h"

class OpenGLEventHandlers
{
public:
	OpenGLEventHandlers();
	~OpenGLEventHandlers();

	static void __cdecl display();
	static void __cdecl reshape(int width, int height);
	static void __cdecl mouse(int button, int state, int x, int y);
	static void __cdecl keyboard(unsigned char key, int x, int y);	

private:
	static int currentPoint;
	static Point points[3];

	static void _clearScreen();
	static void _drawPoint(Point point);
	static void _sierpinski(Point point1, Point point2, Point point3);
	static void _triangle(Point point1, Point point2, Point point3);
	static void _quad(Point point1, Point point2, Point point3, Point point4);
};