#include <iostream>
#include "UI.h"

using namespace std;

int UI::Menu() {
    int key;
    cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
    cin >> key;
    return key;
}

int UI::Shape_Type_Insert() {
    int key;
    cout << "��:1, ��:2, �簢��:3 >>";
    cin >> key;
    return key;
}

int UI::Shape_Delete() {
    int key;
    cout << "�����ϰ��� �ϴ� ������ �ε��� >>";
    cin >> key;
    return key;
}
