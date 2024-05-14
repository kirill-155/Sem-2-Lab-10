#pragma once
//#include <Windows.h>
#include "Header.h"
#include "Point.h"

vector<pair<int, int>> list = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4,0}, {5, 0}, {6, 0}, {7, 0} };

class Button {
private:
    double x;
    double y;
    double width;
    double height;
    string text;
    vector <double> colors = { 0.8,0.8,0.8 };
public:
    Button() : x(0), y(0), width(0), height(0), text("") {};
    Button(double x, double y, double width, double height, string text)
        : x(x), y(y), width(width), height(height), text(text) {};
    Button(const Button& other) : x(other.x), y(other.y), width(other.width), height(other.height), text(other.text) {};
    ~Button() {};

    void setColor(double first, double second, double third) {
        colors[0] = first;
        colors[1] = second;
        colors[2] = third;
    }
    void setPosition(double x_1, double y_1) {
        x = x_1;
        y = y_1;
    }

    void setText(const string text_1) {
        text = text_1;
    }

    void drawButton() {
        //��������� ������
        glBegin(GL_POLYGON);
        glColor3f(colors[0], colors[1], colors[2]); // ����� ����
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // ����� ����
        int textLength = text.size();
        float textX = x + width / textLength - 2;
        float textY = y + height / 2 - 5;

        glRasterPos2f(textX, textY);
        for (int i = 0; i < textLength; i++) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
        }
    }

    bool isButtonHovered(Point& najatie) {
        return najatie.x >= this->x && najatie.x <= this->x + this->width &&
            najatie.y >= this->y && najatie.y <= this->y + this->height;
    }

};

Button bCreate(-40, 255, 80, 40, "Create");
Button bDelete(-40, 210, 80, 40, "Delete");
Button bEdit1(-40, 165, 80, 40, "Edit");
Button bMenu(-145, -255, 60, 30, "Menu");
