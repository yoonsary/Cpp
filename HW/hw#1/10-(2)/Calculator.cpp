#include <iostream>
#include "Calculator.h"
using namespace std;

void Add::setValue(int x, int y) {
    this->x = x;
    this->y = y;
}
int Add::calculate() {
    return x + y;
}

void Sub::setValue(int x, int y) {
    this->x = x;
    this->y = y;
}
int Sub::calculate() {
    return x - y;
}

void Mul::setValue(int x, int y) {
    this->x = x;
    this->y = y;
}
int Mul::calculate() {
    return x * y;
}

void Div::setValue(int x, int y) {
    this->x = x;
    this->y = y;
}
int Div::calculate() {
    return x / y;
}

int main() {
    Add a;
    Sub s;
    Mul m;
    Div d;

    while (true) {
        int x, y;
        char op;
        cout << "두 정수와 연산자를 입력하세요>>";
        cin >> x >> y >> op;

        if (op == '+') {
            a.setValue(x, y);
            cout << a.calculate() << endl;
        }
        else if (op == '-') {
            s.setValue(x, y);
            cout << s.calculate() << endl;
        }
        else if (op == '*') {
            m.setValue(x, y);
            cout << m.calculate() << endl;
        }
        else if (op == '/') {
            d.setValue(x, y);
            cout << "" << d.calculate() << endl;
        }
        else {
            cout << "잘못된 연산자입니다" << endl;
        }
    }

    return 0;
}
