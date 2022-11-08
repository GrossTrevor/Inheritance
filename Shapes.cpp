#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include "Shapes.h"
#define PI 3.14159f
using std::cout;
using std::string;

//Shape2D
void Shape2D::ShowArea() const {
	cout << "The area of the " << this->GetName2D() << " is : " << this->Area() << endl;

}

bool Shape2D::operator>(const Shape2D& rhs) const {
	if (this->Area() > rhs.Area())
		return true;
	return false;
}

bool Shape2D::operator<(const Shape2D& rhs) const {
	if (this->Area() < rhs.Area())
		return true;
	return false;
}

bool Shape2D::operator==(const Shape2D& rhs) const {
	if (this->Area() == rhs.Area())
		return true;
	return false;
}

//Square
Square::Square() {
	side = 0;
}

Square::Square(float s) {
	side = s;
}

void Square::Scale(float scaleFactor) {
	side = this->side * scaleFactor;
}

void Square::Display() const {
	cout << "The area of the Square is : " << this->Area() << endl;
	cout << "Length of a side: " << this->side << endl;
}

float Square::Area() const {
	return side * side;
}

string Square::GetName2D() const {
	return "Square";
}

//Triangle
Triangle::Triangle() {
	base = 0;
	height = 0;
}

Triangle::Triangle(float b, float h) {
	base = b;
	height = h;
}

void Triangle::Scale(float scaleFactor) {
	base = this->base * scaleFactor;
	height = this->height * scaleFactor;
}

void Triangle::Display() const {
	cout << "The area of the Triangle is : " << this->Area() << endl;
	cout << "Base: " << this->base << endl;
	cout << "Height: " << this->height << endl;
}

float Triangle::Area() const {
	return .50f * base * height;
}

string Triangle::GetName2D() const {
	return "Triangle";
}

float Triangle::GetBase() const {
	return base;
}

float Triangle::GetHeight() const {
	return height;
}

//Circle
Circle::Circle() {
	radius = 0;
}

Circle::Circle(float r) {
	radius = r;
}

void Circle::Scale(float scaleFactor) {
	radius *= scaleFactor;
}

void Circle::Display() const {
	cout << "The area of the Circle is : " << this->Area() << endl;
	cout << "Radius: " << this->radius << endl;
}

float Circle::Area() const {
	return PI * (radius * radius);
}

string Circle::GetName2D() const {
	return "Circle";
}

float Circle::GetRadius() const {
	return radius;
}

//Shape3D
void Shape3D::ShowVolume() const {
	cout << "The volume of the " << this->GetName3D() << " is : " << this->Volume() << endl;
}

bool Shape3D::operator>(const Shape3D& rhs) const {
	if (this->Volume() > rhs.Volume())
		return true;
	return false;
}

bool Shape3D::operator<(const Shape3D& rhs) const {
	if (this->Volume() < rhs.Volume())
		return true;
	return false;
}

bool Shape3D::operator==(const Shape3D& rhs) const {
	if (this->Volume() == rhs.Volume())
		return true;
	return false;
}

//Triangular Pyramid
TriangularPyramid::TriangularPyramid() {
	height = 0;
	area = 0;
}

TriangularPyramid::TriangularPyramid(float hP, float b, float hB) {
	height = hP;
	triangle = Triangle(b, hB);
	area = triangle.Area();
}

void TriangularPyramid::Scale(float scaleFactor) {
	height = this->height * scaleFactor;
	area = .50f * (this->triangle.GetBase() * scaleFactor) * (this->triangle.GetHeight() * scaleFactor);
}

void TriangularPyramid::Display() const {
	cout << "The volume of the TriangularPyramid is : " << this->Volume() << endl;
	cout << "The height is: " << this->height << endl;
	triangle.Display();
}

float TriangularPyramid::Volume() const {
	return (1.00f / 3.00f) * area * height;
}

string TriangularPyramid::GetName3D() const {
	return "TriangularPyramid";
}

//Cylinder
Cylinder::Cylinder() {
	height = 0;
	radius = 0;
}

Cylinder::Cylinder(float h, float rad) {
	height = h;
	radius = rad;
	circle = Circle(Cylinder::radius);
}

void Cylinder::Scale(float scaleFactor) {
	height = this->height * scaleFactor;
	radius = this->circle.GetRadius() * scaleFactor;
	circle.Scale(scaleFactor);
}

void Cylinder::Display() const {
	cout << "The volume of the Cylinder is : " << this->Volume() << endl;
	cout << "The height is: " << this->height << endl;
	circle.Display();
}

float Cylinder::Volume() const {
	return PI * (radius * radius) * height;
}

string Cylinder::GetName3D() const {
	return "Cylinder";
}

//Sphere
Sphere::Sphere() {
	radius = 0;
}

Sphere::Sphere(float rad) {
	radius = rad;
	circle = Circle(Sphere::radius);
}

void Sphere::Scale(float scaleFactor) {
	radius = this->circle.GetRadius() * scaleFactor;
}

void Sphere::Display() const {
	cout << "The volume of the Sphere is : " << this->Volume() << endl;
	circle.Display();
}

float Sphere::Volume() const {
	return (4.00f / 3.00f) * PI * (radius * radius * radius);
}

string Sphere::GetName3D() const {
	return "Sphere";
}