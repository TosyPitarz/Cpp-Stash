/*
 Date: 12/7/17
 Version: 1.0
 Copyright: 2017 Peters E. Oluwatosin
 */

/*
 DOCUMENTATION

 Program Purpose: Create a hierachy of shapes and display their information

 Compile: g++ Oop.cpp -o op
 Execution: ./op

 Classes:
   Point
   Circle
   Triangle
   Square
 */

/*
 TEST PLAN
        Normal Case:
            >Prints out the base class routine effect on the object
            >Prints the details about the objects (area, perimeter, circumference)

 */


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int pointX, int pointY): x(pointX), y(pointY) {}
    Point() {
    		x = 0;
    		y = 0;
    }
    int getX();
    int getY();
    void setPoints(int pointx, int pointy);

    double distance(Point point2);
    double distance();

    Point operator-(Point op2);
    Point operator+(Point op2);
    friend ostream& operator<<(ostream& os, Point &p);
};

Point Point::operator-(Point op2){
    Point newop2;
    newop2.x = x - op2.x;
    newop2.y = y - op2.y;
    return newop2;
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

void Point::setPoints(int pointx, int pointy){
	x = pointx;
	y = pointy;
}

double Point::distance(Point point2){
	double distance;
	Point get = point2 - *this;
	distance = sqrt( (get.getX() * get.getX()) + (get.getY() * get.getY()));
	return distance;
}

double Point::distance(){
	double distance;

	distance = sqrt( (this->getX() * this->getX()) + (this->getY() * this->getY()));

	return distance;
}

Point Point::operator+(Point op2){
    Point newop2;
    newop2.x = x + op2.x;
    newop2.y = y + op2.y;
    return newop2;
}

ostream& operator<<(ostream& out, Point &op2){
    cout<< "x:"<<op2.getX() << " " << "y:"<< op2.getY()<<endl;
    return out;
}

class Shape {
public:
    virtual void area(void) = 0;
    virtual void circumference(void) = 0;
    virtual void display(void) = 0;
    virtual ~Shape() = 0;
    void boundingBox(Point point1, Point point2, Point point3, Point point4);
};

Shape::~Shape(){

}

class Circle: public Shape {
    Point point;
    int radius;
public:
	Circle() {
		radius = -1;
	}
	Circle(Point centre, int rad) : point(centre), radius(rad) {}

    void area(void){
    		double result = M_PI *(radius * radius);
		cout << "\nCircle::Area " << result<<endl;
    }

    void circumference(void){
    		double result = 2 * M_PI *radius;
    		cout << "\nCircle::Circumference " << result;
    }

    void boundingBox(void){
    		Point lLeft;
    		Point uRight;

    		int ab, bc;
    		ab = point.getX()- radius;
    		bc = point.getY() - radius;
    		lLeft = Point(ab, bc);

    		int cd, de;
    		cd = point.getX() + radius;
		de = point.getY() + radius;
		uRight = Point(cd, de);

		cout<<lLeft<<uRight;


    }
    void display(void){
    		cout<<"This is a Circle class";
    }

};

class Square: public Shape {
	Point point1, point2, point3, point4;
public:
	Square() {}
	Square(Point p1, Point p2, Point p3, Point p4) : point1(p1),point2(p2),point3(p3),point4(p4) {}

    void area(void) {
    		Point side1 = (point1 - point2);
    		double ab;
    		ab = side1.distance();

    		double result = (ab*ab);
    		std::cout << "\nSquare::area " << result;
    }

    void circumference(void){
    		Point side1 = (point1 - point2);
		double length;
		length = side1.distance();

		double perimeter = 4 * length;
		std::cout << "\nSquare::perimeter " << perimeter<<endl;
    }

    void boundingBox(void){
		Point left, right;
    		int x11, x12, y12, y11, x21,x22, y21, y22;
    		int pointx, pointy, pointz, pointyz;

    		x11 = min(point1.getX(), point2.getX());
    		x12 = min(point3.getX(), point4.getX());
    		pointx = min(x11, y11);

    		y11 = min(point1.getY(), point2.getY());
    		y12 = min(point3.getY(), point4.getY());
    		pointy = min(y11, y12);

    		left.setPoints(pointx, pointy);

    		x21 = max(point1.getX(), point2.getX());
    		x22 = max(point3.getX(), point4.getX());
    		pointz = max(x21, x22);

    		y21 = max(point1.getY(), point2.getY());
    		y22 = max(point3.getY(), point4.getY());
    		pointyz = max(y21, y22);

    		right.setPoints(pointz, pointyz);

    		cout<<left<<right;

	}

    void display(void){
    		cout<<"\nThis is a Square class";
    }
};


class Triangle: public Shape {
	Point point1, point2, point3;
public:
	Triangle() {}

	Triangle(Point p1, Point p2, Point p3) : point1(p1),point2(p2),point3(p3) {}

    void area(void){
    		Point side1 = (point1 - point2);
		Point side2 = (point2 - point3);
		Point side3 = (point3 - point1);

		double half = (side1.distance() + side2.distance() + side3.distance())/2;
		double answer = sqrt(half * (half - side1.distance()) * (half - side2.distance()) * (half - side3.distance()));

		std::cout << "\nTriangle::area " << answer<<endl;
    }

    void circumference(void){
    		Point side1 = (point1 - point2);
		Point side2 = (point2 - point3);
		Point side3 = (point3 - point1);

		double perimeter = side1.distance() + side2.distance() + side3.distance();
		std::cout << "Triangle::perimeter " << setprecision(4)<<perimeter;
    }

    void boundingBox(void){
    		Point left, right;
		int x1, y1,x2,y2;

		x1 = min(min(point1.getX(), point2.getX()), point3.getX());
		y1 = min(min(point1.getY(), point2.getY()), point3.getY());
		left.setPoints(x1, y1);

		x2 = max(max(point1.getX(), point2.getX()), point3.getX());
		y2 = max(max(point1.getY(), point2.getY()), point3.getY());
		right.setPoints(x2, y2);

    		cout<<left<<right;
    }

    void display(void){
    		cout<<"\nThis is a Triangle class"<<endl;
    }
};


int main()
{
    Circle circle = Circle(Point(10, -5), 23);
    circle.display();
    circle.circumference();
    circle.area();
    circle.boundingBox();

    Triangle triangle = Triangle(Point(0, 0), Point(10, 10), Point(-15,15));
	triangle.display();
	triangle.boundingBox();
	triangle.circumference();
	triangle.area();

    Square square = Square(Point(4,1), Point(4,29), Point(32,29), Point(32,1));
    square.display();
    square.area();
    square.circumference();
    square.boundingBox();
}
