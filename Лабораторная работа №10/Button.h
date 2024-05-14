#pragma once
//#include <Windows.h>
#include "Header.h"
#include "Point.h"

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
        //Отрисовка кнопки
        glBegin(GL_POLYGON);
        glColor3f(colors[0], colors[1], colors[2]); // Серый цвет
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Серый цвет
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
