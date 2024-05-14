#pragma once
#include "Header.h"
#include "Button.h"


vector<Point> pointList = { Point(-3, 3), Point(3, -3), Point(3, -4), Point(3, -5) };
vector<Line> lineList = { Line(Point(1.0, 1.0), Point(2.0, 2.0)), Line(5, 5) };
vector<Polygon> polygonList = { Polygon({Point(1.0, 2.0), Point(3.0, 3.0), Point(1.0, 3.0)}) };
vector<Ellipse> ellipseList = { Ellipse(Point(-3, 3), Point(3, -3), 15) };
vector<Circle> circleList = { Circle(Point(1.0, 6.0), 4) };
vector<Rectangle> rectangleList = { Rectangle(Point(1, 3), Point(2, 5), 2) };
vector<Square> squareList = { Square(Point(6, 1), Point(7,2)) };
vector<Triangle> triangleList = { Triangle(Point(-10, -10), Point(-8, -8), Point(-6, -10)) };

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

void Create() {
    glClearColor(0.5, 0.5, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawMenuFigure();
    glFlush();
    glutSwapBuffers();
}
