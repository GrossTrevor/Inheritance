#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#define PI 3.14159f
using std::cout;
using std::string;
using std::endl;

class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape(){}
};

//2D Shapes
class Shape2D : virtual public Shape {
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	virtual ~Shape2D() {}
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Square : public Shape2D {
	float side;
public:
	Square();
	Square(float side);
	~Square() {}
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
};

class Triangle : public Shape2D {
	float base;
	float height;
public:
	Triangle();
	Triangle(float base, float height);
	~Triangle() {}
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
	float GetBase() const;
	float GetHeight() const;
};

class Circle : public Shape2D {
	float radius;
public:
	Circle();
	Circle(float radius);
	~Circle() {}
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	string GetName2D() const;
	float GetRadius() const;
};

//3D Shapes
class Shape3D : virtual public Shape {
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	virtual ~Shape3D() {}
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};

class TriangularPyramid : public Shape3D, private Triangle {
	float height;
	Triangle triangle;
	float area;
public:
	TriangularPyramid();
	TriangularPyramid(float heightPyr, float base, float heightBase);
	~TriangularPyramid() {}
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Cylinder : public Shape3D, private Circle {
	float height;
	Circle circle;
	float radius;
public:
	Cylinder();
	Cylinder(float height, float radius);
	~Cylinder() {}
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};

class Sphere : public Shape3D, private Circle {
	Circle circle;
	float radius;
public:
	Sphere();
	Sphere(float radius);
	~Sphere() {}
	void Scale(float scaleFactor);
	void Display() const;
	float Volume() const;
	string GetName3D() const;
};