#include <iostream>
#include <string>
#include <map>
#include <limits>

class DataBase
{
protected:
	std::map<std::string, unsigned int> _data;

	virtual void inputValidation(const std::string &product, const int &amount)
	{
		if (product.empty())
		{
			throw std::invalid_argument("Product cant be empty string");
		} else if (amount < 0)
		{
			throw std::invalid_argument("Amount cant be less the zero");
		}
	}

	bool find(const std::string &product) noexcept
	{
		return _data.find(product) != _data.end();
	}

public:
	virtual void add(const std::string &product, const int &amount)
	{
		inputValidation(product, amount);
		_data[product] += amount;
	}

	virtual void remove(const std::string &product, const int &amount)
	{
		inputValidation(product, amount);
		if (getAmount(product) < amount)
		{
			throw std::runtime_error("There is less product in stock than you request");
		}
		_data[product] -= amount;
	}

	unsigned int getAmount(const std::string &product)
	{
		if (!find(product))
		{
			throw std::runtime_error("Cant find this product in stock");
		}
		return _data[product];
	}
};

class ShoppingCart : public DataBase
{
private:
	DataBase* _stock;
public:
	explicit ShoppingCart(DataBase* db) : _stock(db)
	{};

	void add(const std::string &product, const int &amount) override
	{
		inputValidation(product, amount);
		_stock->remove(product, amount);
		_data[product] += amount;
	}

	void remove(const std::string &product, const int &amount) override
	{
		inputValidation(product, amount);
		int amountDiff = getAmount(product) < amount;
		if (amountDiff < 0)
		{
			throw std::runtime_error("There is less product in shopping cart than you request");
		}
		_stock->add(product, amount);
		if (amountDiff == 0)
		{
			_data.erase(product);
		} else
		{
			_data[product] -= amount;
		}
	}

	void show() const noexcept
	{
		if (_data.empty())
		{
			std::cout << "Shopping cart: is empty" << std::endl;
		} else
		{
			std::cout << "Shopping cart:" << std::endl;
			for (const auto &product: _data)
			{
				std::cout << product.first << " : " << product.second << std::endl;
			}
		}
	}
};

int main()
{
	DataBase data;
	int i = 0;
	while (true)
	{
		std::string name;
		int amount;
		std::cout << "Vendor code: ";
		std::getline(std::cin, name);
		if (name == "stop") break;
		std::cout << "Amount: ";
		std::cin >> amount;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		try
		{
			data.add(name, amount);
			i++;
		} catch (const std::invalid_argument &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	ShoppingCart cart(&data);
	std::string input;
	while (true)
	{
		std::cout << "Input command: ";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == "add")
		{
			std::string name;
			int amount;
			std::cout << "Vendor code: ";
			std::getline(std::cin, name);
			std::cout << "Amount: ";
			std::cin >> amount;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			try
			{
				cart.add(name, amount);
				i++;
			} catch (const std::invalid_argument &e)
			{
				std::cerr << e.what() << std::endl;
			} catch (const std::runtime_error &e)
			{
				std::cerr << e.what() << std::endl;
			}
		} else if (input == "remove")
		{
			std::string name;
			int amount;
			std::cout << "Vendor code: ";
			std::getline(std::cin, name);
			std::cout << "Amount: ";
			std::cin >> amount;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			try
			{
				cart.remove(name, amount);
				i++;
			} catch (const std::invalid_argument &e)
			{
				std::cerr << e.what() << std::endl;
			} catch (const std::runtime_error &e)
			{
				std::cerr << e.what() << std::endl;
			}
		} else if (input == "show")
		{
			cart.show();
		} else if (input == "quit")
		{
			std::cout << "Quitting the program" << std::endl;
			return 0;
		} else
		{
			std::cerr << "Unknown command" << std::endl;
		}
	}
}
