#include <iostream>
using namespace std;

class Add {
private:
    int a, b;
public:
    void setValue(int x, int y) {
        a = x;
        b = y;
    }
    int calculate() {
        return a + b;
    }
};

class Sub {
private:
    int a, b;
public:
    void setValue(int x, int y) {
        a = x;
        b = y;
    }
    int calculate() {
        return a - b;
    }
};

class Mul {
private:
    int a, b;
public:
    void setValue(int x, int y) {
        a = x;
        b = y;
    }
    int calculate() {
        return a * b;
    }
};

class Div {
private:
    int a, b;
public:
    void setValue(int x, int y) {
        a = x;
        b = y;
    }
    int calculate() {
        if (b == 0) {
            cout << "0으로는 나눌 수 없습니다" << endl;
            return 0;
        }
        return a / b;
    }
};

int main() {
    Add a;
    Sub s;
    Mul m;
    Div d;

    while (true) {
        int x, y;
        char op;
        cout << "두 정수와 연산자를 입력하세요>> ";
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
