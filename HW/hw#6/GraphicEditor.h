#ifndef GRAPHIC_EDITOR_H
#define GRAPHIC_EDITOR_H

#include <vector>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"
#include "UI.h"

class GraphicEditor {
    std::vector<Shape*> shapes;

public:
    ~GraphicEditor();
    void insertShape(int type);
    void deleteShape(int index);
    void show();
    void run();
};

#endif