#pragma once
#include "Header.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Graph2.h"
#include "Button.h"
#include "Edit.h"
#include "Create.h"
#include "Delete.h"

bool deleted = 0;
int menu_sost = 0;

void initGrid() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-wGrid / 2 / scale, wGrid / 2 / scale, -hGrid / 2 / scale, hGrid / 2 / scale);
    glMatrixMode(GL_MODELVIEW);
}

void initMenu() {
    glClearColor(0.5, 0.5, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-wMenu / 2, wMenu / 2, -hMenu / 2, hMenu / 2);
    glMatrixMode(GL_MODELVIEW);
}

void drawGrid() {
    glColor3f(0.0, 1.0, 1.0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    for (int i = -wGrid; i <= wGrid; i++) {
        glVertex2f(i, -hGrid);
        glVertex2f(i, hGrid);
        glVertex2f(-hGrid, i);
        glVertex2f(hGrid, i);
    }
    glEnd();
    glFlush();
}

void drawAxes() {
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(-wGrid, 0);
    glVertex2f(wGrid, 0);
    glVertex2f(0, -hGrid);
    glVertex2f(0, hGrid);
    glEnd();
}

void drawEmAll() {
    for (int i = 0; i < list.size(); i++) {
        switch (list[i].first) {
        case 0:
            pointList[list[i].second].draw();
            break;
        case 1:
            lineList[list[i].second].draw();
            break;
        case 2:
            polygonList[list[i].second].draw();
            break;
        case 3:
            ellipseList[list[i].second].draw();
            break;
        case 4:
            circleList[list[i].second].draw();
            break;
        case 5:
            rectangleList[list[i].second].draw();
            break;
        case 6:
            squareList[list[i].second].draw();
            break;
        case 7:
            triangleList[list[i].second].draw();
            break;
        default:
            break;
        }
        glFlush();   
    }
}

void displayGrid() {
    drawAxes();
    drawGrid();
    drawEmAll();
    glFlush();
}

void Grid() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    displayGrid();
    glutPostRedisplay();
    glFlush();
    glutSwapBuffers();
}

void drawMenu() {
    bCreate.drawButton();
    bDelete.drawButton();
    bEdit1.drawButton();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawMenu();
    glFlush();
    glutSwapBuffers();
}

Button bRotate(-150, 255, 80, 40, "Rotate");
Button bReflexPoint(-150, 255, 80, 40, "Point Reflex");
Button bReflexLine(-150, 255, 80, 40, "Line Reflex");
Button bScale(-150, 255, 80, 40, "Scale");

void mouseClick(int button, int state, int x, int y) {
    double worldX, worldY, worldZ;
    GLint viewport[4];
    GLdouble modelview[16], projection[16];

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glGetIntegerv(GL_VIEWPORT, viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);

        gluUnProject(x, viewport[3] - y, 0, modelview, projection, viewport, &worldX, &worldY, &worldZ);

        Point menuChoice(worldX, worldY);

        if (bCreate.isButtonHovered(menuChoice) && menu_sost == 0) {
            Create();
            menu_sost = 1;
        }
        else if (bDelete.isButtonHovered(menuChoice) && menu_sost == 0) {
            Delete();
            menu_sost = 2;
        }
        else if (bEdit1.isButtonHovered(menuChoice) && menu_sost == 0) {
            Edit();
            menu_sost = 3;
        }
        else if (bMenu.isButtonHovered(menuChoice) && menu_sost != 0) {
            display();
            menu_sost = 0;
        }
        else if (bPoint.isButtonHovered(menuChoice) && menu_sost == 1) {
            PointCreate();
        }
        else if (bLine.isButtonHovered(menuChoice) && menu_sost == 1) {
            LineCreate();
        }
        else if (bPolygon.isButtonHovered(menuChoice) && menu_sost == 1) {
            PolygonCreate();
        }
        else if (bEllipse.isButtonHovered(menuChoice) && menu_sost == 1) {
            EllipseCreate();
        }
        else if (bCircle.isButtonHovered(menuChoice) && menu_sost == 1) {
            CircleCreate();
        }
        else if (bRectangle.isButtonHovered(menuChoice) && menu_sost == 1) {
            RectangleCreate();
        }
        else if (bSquare.isButtonHovered(menuChoice) && menu_sost == 1) {
            SquareCreate();
        }
        else if (bTriangle.isButtonHovered(menuChoice) && menu_sost == 1) {
            TriangleCreate();
        }
        for (int i = 0; i < toDelete.size(); i++) {
            if (toDelete[i].a.isButtonHovered(menuChoice) && menu_sost==2) {
                delFigure(toDelete[i].figure, toDelete[i].ind);
                toDelete.clear();
                Delete();
            }
        }
        for (int i = 0; i < existFig.size(); i++) {
            if (existFig[i].a.isButtonHovered(menuChoice) && menu_sost == 3) {
                Editing(existFig[i]);
                existFig.clear();
                Edit();
            }
        }
    }
}

void menu(int& argc, char**& argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(wMenu, hMenu);
    glutInitWindowPosition(10, 100);
    glutCreateWindow("Меню");

    initMenu();

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);

    glutInitWindowSize(wGrid, hGrid);
    glutInitWindowPosition(510, 100);
    glutCreateWindow("График");

    initGrid();
    glutDisplayFunc(Grid);

    glutMainLoop();
}
