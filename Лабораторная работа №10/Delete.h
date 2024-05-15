#pragma once
#include "Header.h"
#include "Button.h"


vector<toButFigur> toDelete;

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
    glClearColor(0.5, 0.5, 1.0, 1.0);
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
            if (list[i].first == 0 && list[i].second == -1) list.erase(list.begin() + i);
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
