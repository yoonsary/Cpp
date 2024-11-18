#include <iostream>
#include "UI.h"

using namespace std;

int UI::Menu() {
    int key;
    cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
    cin >> key;
    return key;
}

int UI::Shape_Type_Insert() {
    int key;
    cout << "선:1, 원:2, 사각형:3 >>";
    cin >> key;
    return key;
}

int UI::Shape_Delete() {
    int key;
    cout << "삭제하고자 하는 도형의 인덱스 >>";
    cin >> key;
    return key;
}
