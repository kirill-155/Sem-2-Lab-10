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

vector<pair<int, int>> list = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4,0}, {5, 0}, {6, 0}, {7, 0} };

vector<Point> pointList = { Point(-3, 3), Point(3, -3), Point(3, -4), Point(3, -5) };
vector<Line> lineList = { Line(Point(1.0, 1.0), Point(2.0, 2.0)), Line(5, 5) };
vector<Polygon> polygonList = { Polygon({Point(1.0, 2.0), Point(3.0, 3.0), Point(1.0, 3.0)})};
vector<Ellipse> ellipseList = { Ellipse(Point(-3, 3), Point(3, -3), 15) };
vector<Circle> circleList = { Circle(Point(1.0, 6.0), 4) };
vector<Rectangle> rectangleList = { Rectangle(Point(1, 3), Point(2, 5), 2) };
vector<Square> squareList = {Square(Point(6, 1), Point(7,2))};
vector<Triangle> triangleList = { Triangle(Point(-10, -10), Point(-8, -8), Point(-6, -10))};

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

Button bCreate(-40, 255, 80, 40, "Create");
Button bDelete(-40, 210, 80, 40, "Delete");
Button bEdit1(-40, 165, 80, 40, "Edit");
Button bMenu(-145, -255, 60, 30, "Menu");

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

bool deleted = 0;
int menu_sost = 0;

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

struct toDel {
    Button a;
    int figure;
    int ind;
};
vector<toDel> toDelete;

Button bDel(-150, 255, 80, 40, "");

void drawMenuDelFigure(int pick, int x, int y, int i) {
    switch (pick) {
    case 0:
        bDel.setPosition(x, y);
        bDel.setText("Point");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    case 1:
        bDel.setPosition(x, y);
        bDel.setText("Line");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    case 2:
        bDel.setPosition(x, y);
        bDel.setText("Polygon");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    case 3:
        bDel.setPosition(x, y);
        bDel.setText("Ellipse");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    case 4:
        bDel.setPosition(x, y);
        bDel.setText("Circle");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    case 5:
        bDel.setPosition(x, y);
        bDel.setText("Rectangle");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    case 6:
        bDel.setPosition(x, y);
        bDel.setText("Square");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    case 7:
        bDel.setPosition(x, y);
        bDel.setText("Triangle");
        bDel.drawButton();
        toDelete.push_back({ bDel, pick, i });
        break;
    }
}

void Delete() {
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int x = -150, y = 255;
    for (int i = 0; i < list.size(); i++) {
        drawMenuDelFigure(list[i].first, x, y, list[i].second);
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


Button bPoint(-40, 255, 80, 40, "Point");
Button bLine(-40, 210, 80, 40, "Line");
Button bPolygon(-40, 165, 80, 40, "Polygon");
Button bEllipse(-40, 120, 80, 40, "Ellipse");
Button bCircle(-40, 75, 80, 40, "Circle");
Button bRectangle(-40, 30, 80, 40, "Rectangle");
Button bSquare(-40, -15, 80, 40, "Square");
Button bTriangle(-40, -60, 80, 40, "Triangle");

void drawMenuFigure() {

    bPoint.drawButton();
    bLine.drawButton();
    bPolygon.drawButton();
    bEllipse.drawButton();
    bCircle.drawButton();
    bRectangle.drawButton();
    bSquare.drawButton();
    bTriangle.drawButton();
    bMenu.drawButton();
}

void PointCreate() {
    cout << "Введите координаты точки: \n";
    double x, y;
    cin >> x >> y;
    Point a(x, y);
    pointList.push_back(a);
    list.push_back({ 0, pointList.size() - 1 });
}

void LineCreate() {
    int pick;
    cout << "Как вы хотите задать линию?\n1 - Две точки\n2 - Точка и угловой коэффициент\n3 - Угловой коэффициент и сдвиг\n";
    cin >> pick;
    if (pick == 1) {
        cout << "Введите координаты 2х точек последовательно: \n";
        double x, y, x1, y1;
        cin >> x >> y >> x1 >> y1;
        Point a(x, y);
        Point b(x1, y1);
        Line L(a, b);
        lineList.push_back(L);
        list.push_back({ 1, lineList.size() - 1 });
    }
    else if (pick == 2) {
        cout << "Введите координаты точки и угловой коэффициент последовательно: \n";
        double x2, y2, k;
        cin >> x2 >> y2 >> k;
        Point t(x2, y2);
        Line L1(t, k);
        lineList.push_back(L1);
        list.push_back({ 1, lineList.size() - 1 });
    }
    else if (pick == 3) {
        cout << "Введите угловой коэффициент и сдвиг последовательно: \n";
        double k1, d;
        cin >> k1 >> d;
        Line L2(k1, d);
        lineList.push_back(L2);
        list.push_back({ 1, lineList.size() - 1 });
    }
    else {
        cout << "Попробуй в другой раз!";
    }
}

void PolygonCreate() {
    cout << "Введите количество вершин: \n";
    int n;
    cin >> n;
    cout << "Введите точки вершин последовательно: \n";
    vector<Point> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
    }
    Polygon a(A);
    polygonList.push_back(a);
    list.push_back({ 2, polygonList.size() - 1 });
}

void EllipseCreate() {
    cout << "Введите 2 точки(фокусы) и сумму расстояний от эллипса до фокусов: \n";
    Point f1, f2;
    double dist;
    cin >> f1.x >> f1.y >> f2.x >> f2.y >> dist;
    Ellipse a(f1, f2, dist);
    ellipseList.push_back(a);
    list.push_back({ 3, ellipseList.size() - 1 });
}

void CircleCreate() {
    cout << "Введите координаты центра и радиус последовательно: \n";
    Point f;
    double r;
    cin >> f.x >> f.y >> r;
    Circle a(f, r);
    circleList.push_back(a);
    list.push_back({ 4, circleList.size() - 1 });
}

void RectangleCreate() {
    cout << "Введите противоположные вершины прямоугольника и отношение смежных сторон последовательно: \n";
    Point p1, p2;
    double dist;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> dist;
    Rectangle a(p1, p2, dist);
    rectangleList.push_back(a);
    list.push_back({ 5, rectangleList.size() - 1 });
}

void SquareCreate() {
    cout << "Введите противоположные вершины квадрата последовательно: \n";
    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Square a(p1, p2);
    squareList.push_back(a);
    list.push_back({ 6, squareList.size() - 1 });
}

void TriangleCreate() {
    cout << "Введите вершины треугольника: \n";
    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    Triangle a(p1, p2, p3);
    triangleList.push_back(a);
    list.push_back({ 7, triangleList.size() - 1 });
}

void Create() {
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawMenuFigure();
    glFlush();
    glutSwapBuffers();
}

void delFigure(int pick, int ind) {
    switch (pick) {
    case 0:
        pointList.erase(pointList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == 0 && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == 0) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == 0 && list[i].second == -1) list.erase(list.begin()+i);
        }
        break;
    case 1:
        lineList.erase(lineList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == -1) list.erase(list.begin() + i);
        }
        break;
    case 2:
        polygonList.erase(polygonList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == -1) list.erase(list.begin() + i);
        }
        break;
    case 3:
        ellipseList.erase(ellipseList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == -1) list.erase(list.begin() + i);
        }
        break;
    case 4:
        circleList.erase(circleList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == -1) list.erase(list.begin() + i);
        }
        break;
    case 5:
        rectangleList.erase(rectangleList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == -1) list.erase(list.begin() + i);
        }
        break;
    case 6:
        squareList.erase(squareList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == -1) list.erase(list.begin() + i);
        }
        break;
    case 7:
        triangleList.erase(triangleList.begin() + ind);
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == ind) list[i].second = -1;
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick) {
                if (list[i].second > ind) {
                    list[i].second--;
                }
            }
        }
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first == pick && list[i].second == -1) list.erase(list.begin() + i);
        }
        break;
    default:
        break;
    }
}

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
    glClearColor(0.0, 0.0, 1.0, 1.0);
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

Button bRotate(-150, 255, 80, 40, "Rotate");
Button bReflexPoint(-150, 255, 80, 40, "Point Reflex");
Button bReflexLine(-150, 255, 80, 40, "Line Reflex");
Button bScale(-150, 255, 80, 40, "Scale");

void Editing(toEdit& a) {
    
}

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

        if (bCreate.isButtonHovered(menuChoice) && menu_sost==0) {
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
        else if (bPoint.isButtonHovered(menuChoice) && menu_sost==1) {
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
    glutInitWindowPosition(500, 100);
    glutCreateWindow("График");

    initGrid();
    glutDisplayFunc(Grid);

    glutMainLoop();
}
