#include "GraphicEditor.h"
#include <iostream>
using namespace std;

GraphicEditor::~GraphicEditor() {
    for (Shape* shape : shapes) {
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
        cout << "�߸��� ���� �����Դϴ�." << endl;
        return;
    }
    shapes.push_back(p);
    cout << "������ ���ԵǾ����ϴ�." << endl;
}

void GraphicEditor::deleteShape(int index) {
    if (index < 1 || index > shapes.size()) {
        cout << "�߸��� �ε����Դϴ�. ��ȿ�� ������ 1���� " << shapes.size() << "�����Դϴ�." << endl;
        return;
    }
    delete shapes[index - 1];
    shapes.erase(shapes.begin() + (index - 1));
    cout << "������ �����Ǿ����ϴ�." << endl;
}

void GraphicEditor::show() {
    if (shapes.empty()) {
        cout << "������ �����ϴ�!" << endl;
        return;
    }
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << i + 1 << ": ";
        shapes[i]->paint();
    }
}

void GraphicEditor::run() {
    cout << "�׷��� �������Դϴ�." << endl;
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
            cout << "�߸��� �޴��Դϴ�." << endl;
            break;
        }
    }
}
