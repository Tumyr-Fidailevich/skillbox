#include <iostream>
#include <vector>

template<typename T1, typename T2>
class Pair
{
private:
	T1 _key;
	T2 _value;
public:
	explicit Pair() = default;

	explicit Pair(T1 &key, T2 &value) : _key(key), _value(value)
	{}

	T1 getKey()
	{
		return _key;
	}

	T2 getValue()
	{
		return _value;
	}
};

template<typename T1, typename T2>
class Dict
{
private:
	std::vector<Pair<T1, T2>> _dict;
public:
	Dict() = default;

	explicit Dict(std::vector<Pair<T1, T2>> &dict) : _dict(dict)
	{};

	explicit Dict(std::vector<Pair<T1, T2>> &&dict) : _dict(dict)
	{};

	void add(Pair<T1, T2> &pair) noexcept
	{
		_dict.push_back(pair);
	}

	void add(Pair<T1, T2> &&pair) noexcept
	{
		_dict.push_back(pair);
	}

	void remove(T1 &key) noexcept
	{
		for (int i = 0; i < _dict.size(); i++)
		{
			if(_dict[i].getKey() == key)
			{
				_dict.erase(_dict.begin() + i);
			}
		}
	}

	std::vector<Pair<T1, T2>> find(T1 &key) noexcept
	{
		std::vector<Pair<T1, T2>> result;
		for (auto &pair: _dict)
		{
			if (pair.getKey() == key)
			{
				result.push_back(pair);
			}
		}
		return result;
	}

	void print() noexcept
	{
		if (_dict.empty())
		{
			std::cout << "Dictionary is empty" << std::endl;
		} else
		{
			for (auto &pair: _dict)
			{
				std::cout << "Key: " << pair.getKey() << ", Value: " << pair.getValue() << std::endl;
			}
		}
	}
};

int main()
{
	Dict<std::string, int> dict;
	std::string input;
	while (true)
	{
		std::cout << "Input command: ";
		std::cin >> input;
		if (input == "add")
		{
			std::string key;
			int value;
			std::cout << "Input key: ";
			std::cin >> key;
			std::cout << "Input value: ";
			std::cin >> value;
			dict.add(Pair(key, value));
		} else if (input == "remove")
		{
			std::string key;
			std::cout << "Input key: ";
			std::cin >> key;
			dict.remove(key);
		} else if (input == "find")
		{
			std::string key;
			std::cout << "Input key: ";
			std::cin >> key;
			Dict<std::string, int> subDict(dict.find(key));
			subDict.print();
		} else if (input == "print")
		{
			dict.print();
		} else if (input == "quit")
		{
			std::cout << "Quitting the program" << std::endl;
			return 0;
		} else
		{
			std::cout << "Unsupported command" << std::endl;
		}
	}
}
