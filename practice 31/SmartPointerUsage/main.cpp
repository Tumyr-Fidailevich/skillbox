#include <iostream>
#include <memory>
#include <cassert>

class Toy
{
private:
	std::string _name;
public:
	explicit Toy(const std::string& name = "defaultToy") : _name(name)
	{}

	~Toy()
	{
		std::cout << "Toy " << _name << " was dropped " << std::endl;
	}

	std::string getName()
	{
		return _name;
	}
};


class Dog
{
private:
	std::string _name;
	int _age;
	std::shared_ptr<Toy> _lovelyToy;
public:
	explicit Dog(const std::string& name) :Dog(0, name, nullptr)
	{}
	explicit Dog(const std::shared_ptr<Toy>& toy) : Dog(0,"default", toy)
	{}
	explicit Dog(int age = 0, const std::string& name = "default", const std::shared_ptr<Toy>& toy = nullptr)
	{
		assert(age >= 0 && age < 30);
		_age = age;
		_name = name;
		_lovelyToy = toy;
	}
	Dog(const Dog &other)
	{
		_age = other._age;
		_name = other._name;
		_lovelyToy = other._lovelyToy;
	}
	Dog& operator=(const Dog &other)
	{
		if(&other == this)
			return *this;
		_age = other._age;
		_name = other._name;
		_lovelyToy = other._lovelyToy;
		return *this;
	}
	void getToy(std::shared_ptr<Toy> &toy)
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
		}else {
			std::cout << _lovelyToy->getName() << " was dropped" << std::endl;
			_lovelyToy = nullptr;
		}
	}
};

int main()
{
	std::shared_ptr<Toy> ball = std::make_shared<Toy>("ball");
	std::shared_ptr<Toy> bone = std::make_shared<Toy>("bone");
	std::shared_ptr<Toy> frisbee = std::make_shared<Toy>("frisbee");
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
