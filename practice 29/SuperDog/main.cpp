#include <iostream>
#include <vector>

class Talent
{
protected:
	std::string _name = "unknown";
public:
	virtual std::string getTalent() = 0;
	virtual ~Talent() = default;
};

class Swimming : public Talent
{
public:
	Swimming()
	{
		_name = "swimming";
	}
	std::string getTalent() override
	{
		return _name;
	}
};

class Dancing : public Talent
{
public:
	Dancing()
	{
		_name = "dancing";
	}
	std::string getTalent() override
	{
		return _name;
	}
};

class Counting : public Talent
{
public:
	Counting()
	{
		_name = "counting";
	}
	std::string getTalent() override
	{
		return _name;
	}

};

class Dog
{
private:
	std::string _name;
	std::vector<Talent*> talents;
public:
	explicit Dog(const char* name) : _name(name) {}
	~Dog()
    {
        for (auto& talent : talents)
        {
            delete talent;
        }
    }
	void addTalent(Talent* pTalent)
	{
		talents.push_back(pTalent);
	}
	void showTalents()
	{
		std::cout << _name << " knows how to: ";
		for(auto &talent : talents)
		{
			std::cout << talent->getTalent() << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	Dog myDog("Alex");
	Talent* counting = new Counting();
	Talent* swimming = new Swimming();
	Talent* dancing = new Dancing();
	myDog.addTalent(counting);
	myDog.addTalent(swimming);
	myDog.addTalent(dancing);
	myDog.showTalents();
	return 0;
}
