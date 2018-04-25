// Lesson 6: A Simple Animation
// Author: Michael Hall
//
// This C++ code and project are provided "as is"
// without warranty of any kind. For personal use only,
// not for distribution. Copyright 2010 XoaX.
#include<GL/glut.h> //  biblioteca opengl
#include<GL/gl.h>   //  biblioteca opengl

GLfloat gfPosX = 0.0;
GLfloat gfDeltaX = .01;

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(gfPosX, 0.25, 0.0);
		glVertex3f(1.0 - gfPosX, 0.75,0.0);
	glEnd();
	glutSwapBuffers();
	gfPosX += gfDeltaX;
	if (gfPosX >= 1.0 || gfPosX <= 0.0) {
		gfDeltaX = -gfDeltaX;
	}
	glutPostRedisplay();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
