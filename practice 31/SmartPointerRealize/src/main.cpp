#include <iostream>
#include <string>
#include <cassert>
#include "smart_ptr.h"

class Toy
{
private:
	std::string _name;
public:
	explicit Toy(const std::string &name = "default") : _name(name)
	{}

	~Toy()
	{
		std::cout << "Toy " << _name << " was dropped " << std::endl;
	}

	Toy(const Toy &other)
	{
		_name = other._name;
	}

	Toy &operator=(const Toy &other)
	{
		if (&other == this)
			return *this;
		_name = other._name;
		return *this;
	}

	std::string getName() const
	{
		return _name;
	}
};

class Dog
{
private:
	std::string _name;
	int _age;
	shared_ptr<Toy> _lovelyToy;
public:
	//В стандартном конструкторе вместо присваивания к нулевому указателю решил просто создавать стандартный объект
	explicit Dog(int age = 0, const std::string &name = "default", const shared_ptr<Toy> &toy = shared_ptr<Toy>())
	{
		assert(age >= 0 && age < 30);
		_age = age;
		_name = name;
		_lovelyToy = toy;
	}

	//Здесь также вместо nullptr передаю стандартный объект
	explicit Dog(const std::string &name) : Dog(0, name)
	{}

	explicit Dog(const shared_ptr<Toy> &toy) : Dog(0, "default", toy)
	{}

	explicit Dog(const shared_ptr<Toy> &&toy) : Dog(0, "default", toy)
	{}

	Dog(const Dog &other)
	{
		_age = other._age;
		_name = other._name;
		_lovelyToy = other._lovelyToy;
	}

	Dog &operator=(const Dog &other)
	{
		if (&other == this)
			return *this;
		_age = other._age;
		_name = other._name;
		_lovelyToy = other._lovelyToy;
		return *this;
	}

	void getToy(const shared_ptr<Toy> &toy)
	{
		if (_lovelyToy == toy)
		{
			std::cout << "I already have this toy" << std::endl;
		} else if (toy.use_count() > 1)
		{
			std::cout << "Another dog is playing with this toy" << std::endl;
		} else
		{
			_lovelyToy = toy;
		}
	}

	void dropToy()
	{
		if (_lovelyToy == nullptr)
		{
			std::cout << "Nothing to drop" << std::endl;
		} else
		{
			std::cout << _lovelyToy->getName() << " was dropped" << std::endl;
			_lovelyToy = nullptr;
		}
	}
};


int main()
{
	shared_ptr<Toy> ball = make_shared<Toy>("ball");
	shared_ptr<Toy> bone = make_shared<Toy>("bone");
	shared_ptr<Toy> frisbee = make_shared<Toy>("frisbee");
	Dog charlie(10, "Charlie", ball);
	Dog alex(11, "Alex", bone);
	Dog sharik("Sharik");
	charlie.getToy(ball);
	charlie.getToy(bone);
	charlie.dropToy();
	sharik.getToy(ball);
	charlie.dropToy();

	return 0;
}
