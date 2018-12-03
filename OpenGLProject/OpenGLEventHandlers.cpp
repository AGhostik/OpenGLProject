#include "OpenGLEventHandlers.h"
#include "Math.h"

OpenGLEventHandlers::OpenGLEventHandlers() {
}

OpenGLEventHandlers::~OpenGLEventHandlers() {
}

void __cdecl OpenGLEventHandlers::display() {	
	_clearScreen();
}

void __cdecl OpenGLEventHandlers::reshape(int width, int height) {
}

void __cdecl OpenGLEventHandlers::mouse(int button, int state, int x, int y) {
	static int currentPoint;
	static Point points[3];

	if (currentPoint < 0 || currentPoint > 3) {
		currentPoint = 0;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (currentPoint == 3) {
			currentPoint = 0;
			_clearScreen();
		}
		Point point = Point(x, 600 - y);
		_drawPoint(point);		

		points[currentPoint] = point;
		currentPoint++;	
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		currentPoint = 0;
		_clearScreen();
	}
	if (currentPoint == 3) {
		_sierpinski(points[0], points[1], points[2]);
	}
}

void __cdecl OpenGLEventHandlers::keyboard(unsigned char key, int x, int y) {
}

void OpenGLEventHandlers::_clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void OpenGLEventHandlers::_drawPoint(Point point) {
	glColor3f(1, 1, 1);

	glBegin(GL_POINTS);
		glVertex2i(point.x, point.y);
	glEnd();

	glFlush();
}

void OpenGLEventHandlers::_triangle(Point point1, Point point2, Point point3) {
	glBegin(GL_TRIANGLES);

	glVertex2i(point1.x, point1.y);
	glVertex2i(point2.x, point2.y);
	glVertex2i(point3.x, point3.y);

	glEnd();

	glFlush();
}

void OpenGLEventHandlers::_quad(Point point1, Point point2, Point point3, Point point4){
	glBegin(GL_QUADS);

	glVertex2i(point1.x, point1.y);
	glVertex2i(point2.x, point2.y);
	glVertex2i(point3.x, point3.y);
	glVertex2i(point4.x, point4.y);

	glEnd();

	glFlush();
}

void OpenGLEventHandlers::_sierpinski(Point point1, Point point2, Point point3) {
	Math math;
	
	Point triangle[3] = {point1, point2, point3};
	Point point = triangle[math.Random(3)];

	glBegin(GL_POINTS);

	glVertex2i(point.x, point.y);
	for (int i = 0; i < 10000; i++)
	{
		GLint index = math.Random(3);

		GLfloat red = math.Random(0, 1.0f);
		GLfloat green = math.Random(0, 1.0f);
		GLfloat blue = math.Random(0, 1.0f);
		glColor3f(red, green, blue);

		point.x = (point.x + triangle[index].x) / 2;
		point.y = (point.y + triangle[index].y) / 2;
		glVertex2i(point.x, point.y);
	}

	glEnd();

	glFlush();
}