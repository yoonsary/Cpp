#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include "Shape.h"
#include "UI.h"

class GraphicEditor {
    Shape* pStart;
    Shape* pLast;
public:
    GraphicEditor();
    void insertShape(int type);
    void deleteShape(int index);
    void show();
    void run();
};

#endif
