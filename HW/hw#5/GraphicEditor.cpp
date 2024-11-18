#include <iostream>
#include "GraphicEditor.h"
#include "Line.h"
#include "Circle.h"
#include "Rect.h"

using namespace std;

GraphicEditor::GraphicEditor() {
    pStart = pLast = NULL;
}

void GraphicEditor::insertShape(int type) {
    Shape* p = NULL;
    switch (type) {
    case 1:
        p = new Line();
        break;
    case 2:
        p = new Circle();
        break;
    case 3:
        p = new Rectangle();
        break;
    default:
        cout << "잘못된 도형 유형입니다." << endl;
        break;
    }
    if (pStart == NULL) {
        pStart = p;
        pLast = p;
        return;
    }
    pLast->add(p);
    pLast = pLast->getNext();
}

void GraphicEditor::deleteShape(int index) {
    if (pStart == NULL) {
        cout << "도형이 없습니다!" << endl;
        return;
    }

    int count = 0;
    Shape* tmp = pStart;
    while (tmp != NULL) {
        count++;
        tmp = tmp->getNext();
    }

    if (index < 1 || index > count) {
        cout << "잘못된 인덱스입니다. 유효한 범위는 1부터 " << count << "까지입니다." << endl;
        return;
    }

    Shape* pre = NULL;
    tmp = pStart;

    for (int i = 1; i < index; i++) {
        pre = tmp;
        tmp = tmp->getNext();
    }

    if (pre == NULL) {
        pStart = tmp->getNext();
    }
    else {
        pre->add(tmp->getNext());
    }

    delete tmp;
    cout << "도형이 삭제되었습니다." << endl;
}

void GraphicEditor::show() {
    if (pStart == NULL) {
        cout << "도형이 없습니다!" << endl;
        return;
    }
    Shape* tmp = pStart;
    int i = 1;
    while (tmp != NULL) {
        cout << i++ << ": ";
        tmp->paint();
        tmp = tmp->getNext();
    }
}

void GraphicEditor::run() {
    cout << "그래픽 에디터입니다." << endl;
    int menu, index, type;
    while (true) {
        menu = UI::Menu();
        switch (menu) {
        case 1:
            type = UI::Shape_Type_Insert();
            insertShape(type);
            break;
        case 2:
            index = UI::Shape_Delete();
            deleteShape(index);
            break;
        case 3:
            show();
            break;
        case 4:
            return;
        default:
            cout << "잘못된 인덱스입니다." <<endl;
            break;
        }
    }
}
