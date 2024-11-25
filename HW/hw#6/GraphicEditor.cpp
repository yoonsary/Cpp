#include "GraphicEditor.h"
#include <iostream>
using namespace std;

GraphicEditor::~GraphicEditor() {
    for (Shape* shape : v) {
        delete shape;
    }
}

void GraphicEditor::insertShape(int type) {
    Shape* p = nullptr;
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
        return;
    }
    v.push_back(p);
    cout << "도형이 삽입되었습니다." << endl;
}

void GraphicEditor::deleteShape(int index) {
    if (v.empty()) {
        cout << "도형이 없습니다!" << endl;
        return;
    }
    if (index < 1 || index > v.size()) {
        cout << "잘못된 인덱스입니다. 유효한 범위는 1부터 " << v.size() << "까지입니다." << endl;
        return;
    }
    delete v[index - 1];
    v.erase(v.begin() + (index - 1));
    cout << "도형이 삭제되었습니다." << endl;
}

void GraphicEditor::show() {
    if (v.empty()) {
        cout << "도형이 없습니다!" << endl;
        return;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        cout << i + 1 << ": ";
        v[i]->paint();
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
            cout << "잘못된 메뉴입니다." << endl;
            break;
        }
    }
}
