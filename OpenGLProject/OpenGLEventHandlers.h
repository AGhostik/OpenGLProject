#pragma once

class OpenGLEventHandlers
{
public:
	OpenGLEventHandlers();
	~OpenGLEventHandlers();

	static void __cdecl display();
	static void __cdecl reshape(int width, int height);
	static void __cdecl mouse(int button, int state, int x, int y);
	static void __cdecl keyboard(unsigned char key, int x, int y);
};