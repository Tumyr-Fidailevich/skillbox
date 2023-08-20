#include <iostream>
#include <cmath>
#include <cassert>

#define NAME_TO_STR(variable) #variable

struct vector
{
	double x = 0;
	double y = 0;
};

enum color
{
	none,
	red,
	blue,
	green,
	pink
};

class Figure
{
protected:
	double _x = 0;
	double _y = 0;
	int _color = none;
public:
	Figure(double x, double y, int inColor)
	{
		assert(inColor >= 0 && inColor < sizeof(color));
		_x = x;
		_y = y;
		_color = inColor;
	}

	std::string getColor()
	{
		switch (_color)
		{
			case red: return "red";
			case blue: return "blue";
			case green: return "green";
			case pink: return "pink";
			default: return "none";
		}


	}
};

class Rectangle : public Figure
{
private:
	double _width = 0;
	double _height = 0;
public:
	explicit Rectangle(double x, double y, double width, double height, int inColor) : Figure(x, y, inColor)
	{
		assert(width > 0);
		assert(height > 0);
		_width = width;
		_height = height;
	}

	virtual double area()
	{
		return _width * _height;
	}

	Rectangle* circRect()
	{
		return this;
	}

	vector getPos()
	{
		return vector{_x, _y};
	}

	vector getSize()
	{
		return vector{_width, _height};
	}
};

class Square : public Rectangle
{
public:
	explicit Square(double x, double y, double side, int inColor) : Rectangle(x, y, side, side, inColor)
	{}
};

class Circle : public Rectangle
{
private:
	double _radius = 0;
public:
	explicit Circle(double x, double y, double radius, int inColor = none) : Rectangle(x, y, 2 * radius, 2 * radius,
																					   inColor)
	{
		_radius = radius;
	}

	double area() override
	{
		return std::atan(1) * 4 * _radius * _radius;
	}
};

class Triangle : public Rectangle
{
private:
	double _side = 0;
public:
	explicit Triangle(double x, double y, double side, int inColor = none) : Rectangle(x, y, side, side / std::sqrt(2),
																					   inColor)
	{
		_side = side;
	}

	double area() override
	{
		return _side * _side * std::sqrt(3) / 4;
	}
};

int main()
{
	std::string input;
	double x, y;
	std::cout << "Input figure: ";
	std::cin >> input;
	Rectangle* pCircRect = nullptr;
	if (input == "circle")
	{
		double radius;
		std::cout << "Input coordinates: ";
		std::cin >> x >> y;
		std::cout << "Input radius: ";
		std::cin >> radius;
		Circle circle = Circle(x, y, radius, red);
		std::cout << "Color: " << circle.getColor() << std::endl;
		std::cout << "Area: " << circle.area() << std::endl;
		pCircRect = circle.circRect();
	} else if (input == "rectangle")
	{
		double width, height;
		std::cout << "Input coordinates: ";
		std::cin >> x >> y;
		std::cout << "Input width and height: ";
		std::cin >> width >> height;
		Rectangle rectangle = Rectangle(x, y, width, height, pink);
		std::cout << "Color: " << rectangle.getColor() << std::endl;
		std::cout << "Area: " << rectangle.area() << std::endl;
		pCircRect = rectangle.circRect();
	} else if (input == "square")
	{
		double side;
		std::cout << "Input coordinates: ";
		std::cin >> x >> y;
		std::cout << "Input side length: ";
		std::cin >> side;
		Square square = Square(x, y, side, green);
		std::cout << "Color: " << square.getColor() << std::endl;
		std::cout << "Area: " << square.area() << std::endl;
		pCircRect = square.circRect();
	} else if (input == "triangle")
	{
		double side;
		std::cout << "Input coordinates: ";
		std::cin >> x >> y;
		std::cout << "Input side length: ";
		std::cin >> side;
		Triangle triangle = Triangle(x, y, side, blue);
		std::cout << "Color: " << triangle.getColor() << std::endl;
		std::cout << "Area: " << triangle.area() << std::endl;
		pCircRect = triangle.circRect();
	} else
	{
		std::cout << "Invalid command" << std::endl;
		return 1;
	}
	std::cout << "Circumscribed rectangle:" << std::endl;
	std::cout << "Coordinate x: " << pCircRect->getPos().x << std::endl;
	std::cout << "Coordinate y: " << pCircRect->getPos().y << std::endl;
	std::cout << "Width: " << pCircRect->getSize().x << std::endl;
	std::cout << "Height: " << pCircRect->getSize().y << std::endl;
	return 0;
}
