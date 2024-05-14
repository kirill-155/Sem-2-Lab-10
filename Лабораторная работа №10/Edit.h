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

void Editing(toEdit& a) {

}
