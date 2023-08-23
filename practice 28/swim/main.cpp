#include <iostream>
#include <vector>
#include <cassert>
#include <thread>
#include <mutex>

std::mutex mutex;
std::vector<std::string> places;

#define POOL_SIZE 3
#define POOL_DISTANCE 100

class Swimmer
{
private:
	double _speed = 0;
	double _distance = 0;
	std::string _name;
public:
	Swimmer(double speed, const std::string &name) : _speed(speed), _name(name)
	{
		assert(speed > 0);
	}

	void move(const int dt = 1)
	{
		while (_distance < POOL_DISTANCE)
		{
			_distance = _distance + _speed * dt > POOL_DISTANCE ? POOL_DISTANCE : _distance + _speed * dt;
			std::this_thread::sleep_for(std::chrono::seconds(dt));
			mutex.lock();
			std::cout << _name << " swam a distance of " << _distance << " meters" << std::endl;
			mutex.unlock();
		}
		mutex.lock();
		std::cout << _name << " finished" << std::endl;
		places.push_back(_name);
		mutex.unlock();
	}

	std::string getName() const
	{
		return _name;
	}

	double getDistance() const
	{
		return _distance;
	}
};

int main()
{
	std::vector<Swimmer> lines;
	for (unsigned int i = 0; i < POOL_SIZE; i++)
	{
		std::string name;
		double speed;
		std::cout << "Input " << i + 1 << " swimmer name: ";
		std::cin >> name;
		std::cout << "Input " << i + 1 << " swimmer speed: ";
		std::cin >> speed;
		lines.emplace_back(speed, name);
	}

	std::vector<std::thread> threads;
	threads.reserve(lines.size());
	for (auto &swimmer: lines)
	{
		threads.emplace_back([&swimmer]() -> void { swimmer.move(); });
	}
	for (auto &thread: threads)
	{
		thread.join();
	}
	for(int i = 0; i < POOL_SIZE; i++)
	{
		std::cout << places[i] << " take " << i + 1 << " place" << std::endl;
	}
	return 0;
}
