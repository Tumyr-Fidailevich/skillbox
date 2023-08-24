#include <iostream>
#include <cmath>
#include <cassert>

#define NAME_TO_STR(variable) #variable

struct vector
{
	double x = 0;
	double y = 0;
};

class Rectangle;

class Shape
{
protected:
	std::string _type = "unknown";
public:

	virtual double square() = 0;

	virtual Rectangle boundingBox() = 0;

	virtual std::string type() = 0;

	static void describe(Shape* shape);

};

class Rectangle : public Shape
{
private:
	double _width = 0;
	double _height = 0;
public:
	explicit Rectangle(double width, double height)
	{
		assert(width > 0 && height > 0);
		_width = width;
		_height = height;
		_type = "rectangle";
	}

	double square() override
	{
		return _width * _height;
	}

	Rectangle boundingBox() override
	{
		return Rectangle(_width, _height);
	}

	std::string type() override
	{
		return _type;
	}

	vector getParams()
	{
		return vector{_width, _height};
	}
};

void Shape::describe(Shape* shape)
{
	std::cout << "Type: " << shape->type() << std::endl;
	std::cout << "Square: " << shape->square() << std::endl;
	std::cout << "Bounding box parameters: " << std::endl;
	Rectangle box = shape->boundingBox();
	std::cout << "Width: " << box.getParams().x << std::endl;
	std::cout << "Height: " << box.getParams().y << std::endl;
}


class Circle : public Shape
{
private:
	double _radius = 0;
public:
	explicit Circle(double radius) : _radius(radius)
	{
		assert(radius > 0);
		_type = "circle";
	}

	double square() override
	{
		return std::atan(1) * 4 * _radius * _radius;
	}

	Rectangle boundingBox() override
	{
		return Rectangle(2 * _radius, 2 * _radius);
	}

	std::string type() override
	{
		return _type;
	}

};

class Triangle : public Shape
{
private:
	double _a = 0;
	double _b = 0;
	double _c = 0;
	double _p = (_a + _b + _c) / 2;
public:
	explicit Triangle(double a, double b, double c) : _a(a), _b(b), _c(c), _p((a + b + c) / 2)
	{
		assert(a > 0);
		assert(b > 0);
		assert(c > 0);
		assert(a + b > c && a + c > b && b + c > a);
		_type = "triangle";
	}

	double square() override
	{
		return sqrt(_p * (_p - _a) * (_p - _b) * (_p - _c));
	}

	Rectangle boundingBox() override
	{
		double side = (_a * _b * _c) / (4 * square());
		return Rectangle(2 * side, 2 * side);
	}

	std::string type() override
	{
		return _type;
	}
};

int main()
{
	Shape* rectangle = new Rectangle(2, 2);
	Shape* circle = new Circle(2);
	Shape* triangle = new Triangle(3, 4, 5);
	Shape::describe(rectangle);
	Shape::describe(circle);
	Shape::describe(triangle);
	return 0;
}
