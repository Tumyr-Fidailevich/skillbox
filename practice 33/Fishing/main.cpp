#include <iostream>
#include <vector>
#include <cstdlib>
#include <exception>
#include <ctime>

enum
{
	empty,
	fish,
	boot,
};

class Exception : std::exception
{
private:
	std::string _message = "default";
public:
	Exception() = default;

	explicit Exception(const std::string &message) : _message(message)
	{}

	const char* what() const noexcept override
	{
		return _message.c_str();
	}
};

class GameField
{
private:
	std::vector<int> _field = std::vector<int>(9, empty);
public:
	explicit GameField()
	{
		std::srand(std::time(nullptr));
		std::vector<int> fields = {0, 1, 2, 3, 4, 5, 6, 7, 8};
		for (int i = 0; i < 3; i++)
		{
			int rnd = fields[std::rand() % fields.size()];
			_field[rnd] = boot;
			fields.erase(fields.begin() + rnd);
		}
		int rnd = fields[std::rand() % fields.size()];
		_field[rnd] = fish;
	}

	int castRod()
	{
		int pos = 0, count = 1;
		while (pos < _field.size())
		{
			std::cout << "Cast a fishing rod: ";
			std::cin >> pos;
			if (pos < 0 || pos >= _field.size())
			{
				std::cout << "Wrong position" << std::endl;
			} else if (_field[pos] == boot)
			{
				return boot;
			} else if (_field[pos] == fish)
			{
				throw Exception("You caught the fish for " + std::to_string(count) + " attempts!\n");
			}
			count++;
		}
	}
};

int main()
{
	GameField gameField;
	try
	{
		int result = gameField.castRod();
		std::cout << "You caught the boot!" << std::endl;
	}catch(const Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
