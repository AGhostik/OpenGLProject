#include "OpenGLEventHandlers.h"
#include "Point.h"
#include "Math.h"

OpenGLEventHandlers::OpenGLEventHandlers()
{
}

OpenGLEventHandlers::~OpenGLEventHandlers()
{
}

void __cdecl OpenGLEventHandlers::display() {	
	Math math;

	glClear(GL_COLOR_BUFFER_BIT);	

	glPointSize(2);
	glColor3f(1.0, 1.0, 0);

	Point triangle[3] = {Point(0, 0), Point(400, 600), Point(800, 0)};
	Point point = triangle[math.Random(3)];

	glBegin(GL_POINTS);

	glVertex2i(point.x, point.y);
	for (int i = 0; i < 10000; i++)
	{
		int index = math.Random(3);

		float red = math.Random(0, 1.0);
		float green = math.Random(0, 1.0);
		float blue = math.Random(0, 1.0);
		glColor3f(red, green, blue);

		point.x = (point.x + triangle[index].x) / 2;
		point.y = (point.y + triangle[index].y) / 2;
		glVertex2i(point.x, point.y);
	}

	glEnd();

	glFlush();
}

void __cdecl OpenGLEventHandlers::reshape(int width, int height) {
	
}

void __cdecl OpenGLEventHandlers::mouse(int button, int state, int x, int y) {
}

void __cdecl OpenGLEventHandlers::keyboard(unsigned char key, int x, int y) {
}