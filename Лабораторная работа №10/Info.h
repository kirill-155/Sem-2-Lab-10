#pragma once
#include "Header.h"
#include "Button.h"


vector<toButFigur> ButInfo;

Button bInf(-150, 255, 80, 40, "");

void drawMenuInfoFigure(int pick, int i, int x, int y) {
    switch (pick) {
    case 0:
        bInfo.setPosition(x, y);
        bInfo.setText("Point");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    case 1:
        bInfo.setPosition(x, y);
        bInfo.setText("Line");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    case 2:
        bInfo.setPosition(x, y);
        bInfo.setText("Polygon");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    case 3:
        bInfo.setPosition(x, y);
        bInfo.setText("Ellipse");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    case 4:
        bInfo.setPosition(x, y);
        bInfo.setText("Circle");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    case 5:
        bInfo.setPosition(x, y);
        bInfo.setText("Rectangle");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    case 6:
        bInfo.setPosition(x, y);
        bInfo.setText("Square");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    case 7:
        bInfo.setPosition(x, y);
        bInfo.setText("Triangle");
        bInfo.drawButton();
        ButInfo.push_back({ bInfo, pick, i });
        break;
    }
}

void Info() {
    glClearColor(0.5, 0.5, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int x = -150, y = 255;
    for (int i = 0; i < list.size(); i++) {
        drawMenuInfoFigure(list[i].first, list[i].second, x, y);
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

