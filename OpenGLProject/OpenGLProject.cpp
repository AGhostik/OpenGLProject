#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glut.h"
#include "OpenGLEventHandlers.h"

void init() {
	glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL");
	
	glutDisplayFunc(OpenGLEventHandlers::display);
	glutReshapeFunc(OpenGLEventHandlers::reshape);
	glutMouseFunc(OpenGLEventHandlers::mouse);
	glutKeyboardFunc(OpenGLEventHandlers::keyboard);

	init();

	glutMainLoop();
}