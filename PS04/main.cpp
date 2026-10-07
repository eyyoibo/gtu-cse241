#include <iostream>

using namespace std;

class Vector2D {
private:
    int x;
    int y;

public:
    Vector2D() {
        x = 0;
        y = 0;
    }

    Vector2D(int xValue, int yValue) {
        x = xValue;
        y = yValue;
    }

    int GetX() const {
        return x;
    }

    int GetY() const {
        return y;
    }

    void SetX(int xValue) {
        x = xValue;
    }

    void SetY(int yValue) {
        y = yValue;
    }

    int operator*(const Vector2D& other) const {
        return (x * other.x) + (y * other.y);
    }
};

int main() {
    Vector2D v1(10, 0), v2(0, 10), v3(10, 10), v4(5, 4);

    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()
         << "," << v2.GetY() << ") = " << v1 * v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX()
         << "," << v3.GetY() << ") = " << v2 * v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX()
         << "," << v4.GetY() << ") = " << v3 * v4 << endl;

    return 0;
}
