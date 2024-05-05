#pragma once
#include <iostream>
#include "glut.h"

int W = 2000;
int H = 1000;

double Scale = 1;

double width = Scale * W;
double height = Scale * H;

void rand_RGB(double& R, double& G, double& B)
{
	R = ((rand() % 20) - 6) / 10.0;
	G = ((rand() % 20) - 4) / 10.0;
	B = ((rand() % 20) - 3) / 10.0;
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width / 2, width * 3 / 2, -height, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
}

void OXY()
{
	glBegin(GL_LINES);
	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = -height; i <= height; i+=20) {
		glVertex2f(i, -height);
		glVertex2f(i, height);
		glVertex2f(-width/2, i);
		glVertex2f(width/2, i);
	}
	glEnd();

	glLineWidth(4.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);

	glVertex2i(0, -height);
	glVertex2i(0, height);
	glVertex2i(-width/2, 0);
	glVertex2i(width/2, 0);

	glEnd();
	glFlush();
}

void Interface() {
	glColor3f(0.5, 0.5, 1.0);
	glBegin(GL_QUADS); 
	glVertex2f(width/2, height);
	glVertex2f(width * 3 / 2, height);
	glVertex2f(width * 3 / 2, -height);
	glVertex2f(width/2, -height);
	glEnd();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	OXY();
	Interface();
	glFlush();
}

void mouse(int button, int state, int x, int y) {
	// Действие при нажатии левой кнопки мыши
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		std::cout << "On left mouse button click action\n";
	}
	// Действие при нажатии правой кнопки мыши
	else if (button == GLUT_RIGHT_BUTTON && state ==
		GLUT_DOWN) {
		std::cout << "On right mouse button click action\n";
	}
}

void keyboard_cop(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		// Действие при нажатии клавиши ESC
		exit(0);
		break;
	case 'a':
		// Действие при нажатии клавиши ’a’ на английской раскладке
		std::cout << "Action on pressing the 'a' key\n";
		break;
	case 'b':
		// Действие при нажатии клавиши ’b’ на английской раскладке
		std::cout << "Action on pressing the 'b' key\n";
		break;
	}
}

void timer(int = 0)
{
	display();
	glutTimerFunc(100, timer, 0);
}

