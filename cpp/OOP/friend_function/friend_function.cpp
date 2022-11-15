#include <iostream>

using namespace std;

class Box {
private:
    float width, height;
public:

    Box(int w, int h) :
        width(w), height(h)
    {}

    friend void toString(Box box);

    void setWidth(float w);
    void setHeight(float h);
};

void Box::setWidth(float w) {
    width = w;
}

void Box::setHeight(float h) {
    height = h;
}

// getWidth() || getHeigth() are not a member function of any class
void toString(Box box) {
    cout << "Measerues: \nwidth = " << box.width <<
        "\nheight = " << box.height;
}

int main()
{
    Box box(10,20);
//    box.setWidth(10);
//    box.setHeight(20);

    toString(box);

    return 0;
}

// funkcja, która ma dostep do prywatnych skladnikow klasy
