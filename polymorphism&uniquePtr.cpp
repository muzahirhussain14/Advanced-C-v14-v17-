#include<iostream>
#include<vector>
#include <memory>

using namespace std;

class Shape {

    public:
        virtual void draw() =0;
        virtual ~Shape() {
            cout << "Shape Destructor called\n";
        }
};

class Circle : public Shape {

    public:
        virtual void draw() {
            cout << "Drawn Circle\n";
        }

        virtual ~Circle() {
            cout << "Circle Destructor called\n";
        }
};

class Triangle : public Shape {
    
    public:
        virtual void draw() {
            cout << "Drawn Triangle\n";
        }

        virtual ~Triangle() {
            cout << "Triangle Destructor called\n";
        }
};

class Rectangle : public Shape {

    public:
        virtual void draw() {
            cout << "Drawn Rectangle\n";
        }

        virtual ~Rectangle() {
            cout << "Rectangle Destructor called\n";
        }
};

int main() {

    // *************** without unique_ptr *****************
    vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Triangle());
    shapes.push_back(new Rectangle());

    for (Shape *s : shapes) {
        s->draw();
    }

    //  delete memory manually
    for (auto& s : shapes) {
        delete s;
    }


    // ************** with unique_ptr *************
    vector<unique_ptr<Shape>> shapes2;
    shapes2.push_back(make_unique<Circle>(Circle()));
    shapes2.push_back(make_unique<Triangle>(Triangle()));
    shapes2.push_back(make_unique<Rectangle>(Rectangle()));

    cout << "\n\n";
    for (auto& s : shapes2) {
        s->draw();
    }
}