#include <iostream>
#include <vector>
#include <cassert>

enum taskTypes
{
	none = 48,
	A = 65,
	B = 66,
	C = 67
};

class Head
{
private:
	std::string _name;
public:
	explicit Head(const std::string &name) : _name(name)
	{}

	std::string getName()
	{
		return _name;
	}
};

class Worker : public Head
{
private:
	int _task = none;
public:
	explicit Worker(const std::string &name) : Head(name)
	{}

	void setTask(int &task)
	{
		_task = task;
	}

	int getTask()
	{
		return _task;
	}

};

class Manager : public Head
{
private:
	int _id = 0;
public:
	explicit Manager(const std::string &name, int id) : Head(name)
	{
		_id = id;
	}

	int getId()
	{
		return _id;
	}

};


class Team
{
private:
	Manager _manager;
	std::vector<Worker> _workers;
	int _tasksCount = 0;
public:
	Team(Manager &manager, int workersCount) : _manager(manager)
	{
		for (int i = 0; i < workersCount; i++)
		{
			std::string name = "Worker" + std::to_string(_manager.getId()) + std::to_string(i);
			_workers.emplace_back(name);
		}
	}

	Manager getManager()
	{
		return _manager;
	}

	std::vector<Worker> getWorkers()
	{
		return _workers;
	}

	int getTasksCount()
	{
		return _tasksCount;
	}

	void setTasks(int &task)
	{
		assert(!_workers.empty());
		std::srand(_manager.getId() + task);
		if(_tasksCount < _workers.size())
		{
			int tasksCount = 1 + std::rand() % (_workers.size() - _tasksCount);
			for (int i = _tasksCount; i < tasksCount; i++)
			{
				int workerTask = A + std::rand() % (C - A + 1);
 				_workers[i].setTask(workerTask);
			}
			_tasksCount = tasksCount;
		}

	}
};

class Company
{
private:
	Head _head = Head("Head");
	std::vector<Team> _teams;

	bool isFull()
	{
		for (auto &_team: _teams)
		{
			if (_team.getTasksCount() < _team.getWorkers().size())
			{
				return false;
			}
		}
		return true;
	}

public:
	void fillCompany()
	{
		int teamsNumber = 0;
		std::cout << "Input number of teams: ";
		std::cin >> teamsNumber;
		for (int i = 0; i < teamsNumber; i++)
		{
			int workerCount = 0;
			std::string name = "Manager" + std::to_string(i);
			std::cout << "Input number of workers in " << i << " team: ";
			std::cin >> workerCount;
			Manager manager = Manager(name, i);
			_teams.emplace_back(manager, workerCount);
		}
	}

	void print()
	{
		std::cout << "Head of company: " << _head.getName() << std::endl;
		for (auto &_team: _teams)
		{
			std::cout << _team.getManager().getName() << std::endl;
			for (auto &_worker: _team.getWorkers())
			{
				std::cout << _worker.getName() << " doing task " << (char) _worker.getTask() << std::endl;
			}
		}
		std::cout << "----------------------------------" << std::endl;
	}

	void setTasks()
	{
		while (!isFull())
		{
			int task;
			std::cout << "Input task: ";
			std::cin >> task;
			for (auto &_team: _teams)
			{
				_team.setTasks(task);
			}
			print();
		}

	}
};

int main()
{
	Company company = Company();
	company.fillCompany();
	company.setTasks();
	company.print();
	return 0;
}
