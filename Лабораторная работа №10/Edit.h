#pragma once
#include "Header.h"
#include "Button.h"


struct toEdit {
    Button a;
    int figure;
    int ind;
};

vector<toEdit> existFig;

Button bEdit(-150, 255, 80, 40, "");

void drawMenuEditFigure(int pick, int i, int x, int y) {
    switch (pick) {
    case 0:
        bEdit.setPosition(x, y);
        bEdit.setText("Point");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    case 1:
        bEdit.setPosition(x, y);
        bEdit.setText("Line");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    case 2:
        bEdit.setPosition(x, y);
        bEdit.setText("Polygon");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    case 3:
        bEdit.setPosition(x, y);
        bEdit.setText("Ellipse");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    case 4:
        bEdit.setPosition(x, y);
        bEdit.setText("Circle");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    case 5:
        bEdit.setPosition(x, y);
        bEdit.setText("Rectangle");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    case 6:
        bEdit.setPosition(x, y);
        bEdit.setText("Square");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    case 7:
        bEdit.setPosition(x, y);
        bEdit.setText("Triangle");
        bEdit.drawButton();
        existFig.push_back({ bEdit, pick, i });
        break;
    }
}

void Edit() {
    glClearColor(0.5, 0.5, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int x = -150, y = 255;
    for (int i = 0; i < list.size(); i++) {
        drawMenuEditFigure(list[i].first, list[i].second, x, y);
        y -= 45;
        if (y <= -255) {
            x += 85;
            y = 255;
        }
    }
    bMenu.drawButton();
    glFlush();
    glutSwapBuffers();
}

Button bRotate(-40, 255, 110, 40, "Rotate");
Button bReflexPoint(-40, 210, 110, 40, "Point Reflex");
Button bReflexLine(-40, 165, 110, 40, "Line Reflex");
Button bScale(-40, 120, 110, 40, "Scale");

void EdDraw() {
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    bRotate.setColor(0.9, 0.0, 0.5);
    bReflexPoint.setColor(0.9, 0.0, 0.5);
    bReflexLine.setColor(0.9, 0.0, 0.5);
    bScale.setColor(0.9, 0.0, 0.5);

    bRotate.drawButton();
    bReflexPoint.drawButton();
    bReflexLine.drawButton();
    bScale.drawButton();
    bMenu.drawButton();

    glFlush();
    glutSwapBuffers();
}

void Editing(toEdit& a, int func) {
    if (func == 0) {
        cout << "¬ведите координаты точки, относительно которой будет производитьс€ вращение и угол в градусах, на который будет произведен поворот: \n";
        Point p;
        cin >> p.x >> p.y;
        double rad;
        cin >> rad;
        double crad = rad * M_PI / 180.0;
        switch (a.figure) {
        case 0:
            pointList[a.ind].rotate(p, crad);
            break;
        case 1:
            lineList[a.ind].rotate(p, crad);
            break;
        case 2:
            polygonList[a.ind].rotate(p, rad);
            break;
        case3:
            ellipseList[a.ind].rotate(p, rad);
            break;
        case 4:
            circleList[a.ind].rotate(p, rad);
            break;
        case 5:
            rectangleList[a.ind].rotate(p, rad);
            break;
        case 6:
            squareList[a.ind].rotate(p, rad);
            break;
        case 7:
            triangleList[a.ind].rotate(p, rad);
            break;
        default:
            break;
        }
    }
    else if (func == 1) {
        cout << "¬ведите координаты точка, относительно которой будет произведена симметри€: \n";
        Point p;
        cin >> p.x >> p.y;
        switch (a.figure) {
        case 0:
            pointList[a.ind].reflect(p);
            break;
        case 1:
            //lineList[a.ind].reflect(p);
            break;
        case 2:
            polygonList[a.ind].reflex(p);
            break;
        case 3:
            ellipseList[a.ind].reflex(p);
            break;
        case 4:
            circleList[a.ind].reflex(p);
            break;
        case 5:
            rectangleList[a.ind].reflex(p);
            break;
        case 6:
            squareList[a.ind].reflex(p);
            break;
        case 7:
            triangleList[a.ind].reflex(p);
            break;
        default: break;
        }
    }
    else if (func == 2) {
        cout << "¬ведите координаты 2х точек, которыми задастс€ лини€, через которую будет произведена симметри€: \n";
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        Line l1(p1, p2);
        switch (a.figure) {
        case 0:
            pointList[a.ind].reflect(l1);
            break;
        case 1:
            lineList[a.ind].reflex(l1);
            break;
        case 2:
            polygonList[a.ind].reflex(l1);
            break;
        case 3:
            ellipseList[a.ind].reflex(l1);
            break;
        case 4:
            circleList[a.ind].reflex(l1);
            break;
        case 5:
            rectangleList[a.ind].reflex(l1);
            break;
        case 6:
            squareList[a.ind].reflex(l1);
            break;
        case 7:
            triangleList[a.ind].reflex(l1);
            break;
        default: break;
        }
    }
    else if (func == 3) {
        cout << "¬ведиете координаты точки относительно которой будет измен€ть размер, и коэффициент изменени€: \n";
        Point p;
        double coef;
        cin >> p.x >> p.y >> coef;
        switch (a.figure) {
        case 0:
            pointList[a.ind].scale(p, coef);
            break;
        case 1:
            //lineList[a.ind].scale(p, coef);
            break;
        case 2:
            polygonList[a.ind].scale(p, coef);
            break;
        case 3:
            ellipseList[a.ind].scale(p, coef);
            break;
        case 4:
            circleList[a.ind].scale(p, coef);
            break;
        case 5:
            rectangleList[a.ind].scale(p, coef);
            break;
        case 6:
            squareList[a.ind].scale(p, coef);
            break;
        case 7:
            triangleList[a.ind].scale(p, coef);
            break;
        default: break;
        }
    }

}

toEdit global;
