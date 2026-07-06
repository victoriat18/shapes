//Shapes lab
#include <iostream>
#include <cmath>

using namespace std;
//base classes
class Shape {
    protected: 
    string name;

    public:
    Shape(string n){
        name = n;
    }
    //Pure virtual functions
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    //Returns shape name
    string getName() {
        return name;
    }
    //virtual destructor
    virtual ~Shape(){}
}; // closes

//Circle class
class Circle: public Shape {
    private:
    double radius;

    public:
    Circle (double r): Shape("Circle") {
        radius = r;
    }
    double getArea() override {
        return M_PI * radius * radius;
    }
    double getPerimeter() override {
        return 2 * M_PI * radius;
    }
}; //closes

//Rectangle class
class Rectangle: public Shape {
    protected:
    double length;
    double width;

    public:
    Rectangle(double l, double w): Shape("Rectangle"){
        length = l;
        width = w;
    }
    double getArea() override {
        return length * width;
    }
    double getPerimeter() override{
        return 2 * (length + width);
    }
}; //closes

//Square class
class Square: public Rectangle {
    public:
    Square(double side) : Rectangle(side, side) {
        name = "Square";
    }
};//closes

//Right Triangle class
class RightTriangle: public Shape {
protected:
    double base;
    double height;
public:
RightTriangle(double b, double h) : Shape("Right Triangle"){
    base = b;
    height = h;
}
double getArea() override {
    return (base * height) / 2;
}
double getPerimeter() override{
    return base + height + sqrt(base * base + height * height);
    }
};
//Isosceles Right Triangle class
class IsoscelesRightTriangle: public RightTriangle {
public:
IsoscelesRightTriangle(double side): RightTriangle(side, side){
    name = "Isosceles Right Triangle";
}
}; //closes
//Print shape name and area
void printAreaToScreen(Shape* s) {
    cout << s->getName() << " Area: " << s->getArea() << endl;
}

int main(){
    Circle c(5);
    Rectangle r(4,6);
    Square s(4);
    RightTriangle rt(3,4);
    IsoscelesRightTriangle it(5);

    printAreaToScreen(&c);
    printAreaToScreen(&r);
    printAreaToScreen(&s);
    printAreaToScreen(&rt);
    printAreaToScreen(&it);

    return 0;
}