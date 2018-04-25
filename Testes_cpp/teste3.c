
#include<GL/glut.h>
#include<GL/gl.h>

GLfloat pointVertex[] = {0.1, 0.1};

void display() {
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2,GL_FLOAT,0,pointVertex);
    glDrawArrays(GL_POINTS,0,1);
    glDisableClientState(GL_VERTEX_ARRAY);
    
    glFlush();
}

void main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,500);
    glutCreateWindow("Hello World");
    glutDisplayFunc(display);
    glutMainLoop();
}
