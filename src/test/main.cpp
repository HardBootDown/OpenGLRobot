#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/*
sudo apt install freeglut3-dev
g++ main.cpp -o legacy_glut_app -lGL -lGLU -lglut

*/

float angle = 0.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -5.0f);  // Move back
    glRotatef(angle, 0.0f, 1.0f, 0.0f);  // Rotate around Y-axis

    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); glVertex3f(-1, -1, 0);
        glColor3f(0, 1, 0); glVertex3f(1, -1, 0);
        glColor3f(0, 0, 1); glVertex3f(0, 1, 0);
    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0f;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();            // Mark the window for redrawing
    glutTimerFunc(16, update, 0);   // 60 FPS timer
}

void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing
    glClearColor(0, 0, 0, 1);  // Background color: black
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Legacy OpenGL with GLUT");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();  // Enter the GLUT event processing loop
    return 0;
}
