#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "GlutSettings.h"

void solve() {
	display();

}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(width, height);// Размер окна
	glutInitWindowPosition(0, 0);// позиция открытия
	glutCreateWindow("Лабораторная работа 10");// Заголовок окна
	init();
	glutDisplayFunc(solve);
	glutMainLoop();

}
