#include <iostream>
#include <vector>
#include <cassert>
#include <thread>
#include <mutex>
#include <stdexcept>

#define TRAIN_NUMBER 3

std::mutex mutex;
bool stationStatus = true;

class Train
{
private:
	unsigned int _destinationTime = 0;
	char _name = '0';
public:
	explicit Train(int destinationTime, const char name) : _destinationTime(destinationTime), _name(name)
	{
		assert(destinationTime > 0);
	}

	void arrival() const
	{
		std::string command;
		std::this_thread::sleep_for(std::chrono::seconds(_destinationTime));
		if (stationStatus)
		{
			mutex.lock();
			std::cout << _name << " train arrived" << std::endl;
			stationStatus = false;
			mutex.unlock();
		} else
		{
			mutex.lock();
			std::lock_guard<std::mutex> lock(mutex);
			std::cout << _name << " train waiting for free space" << std::endl;
			mutex.unlock();
		}

		do
		{
			std::cin.clear();
			std::cin >> command;
		} while (command != "depart");
		mutex.lock();
		stationStatus = true;
		std::cout << _name << " train depart from the station" << std::endl;
		mutex.unlock();
	}
};


int main()
{
	auto railwayStation = new Train* [TRAIN_NUMBER];
	for (int i = 0; i < TRAIN_NUMBER; i++)
	{
		std::string time;
		std::cout << "Input destination time: ";
		std::cin >> time;
		try {
			std::stoi(time);
		}catch(std::invalid_argument const &e)
		{
			std::cout << "Cannot convert to int" << std::endl;
			return 1;
		}
		railwayStation[i] = new Train(std::stoi(time), (char) ('A' + i));
	}
	std::vector<std::thread> threads;
	threads.reserve(TRAIN_NUMBER);
	for (int i = 0; i < TRAIN_NUMBER; i++)
	{
		auto train = railwayStation[i];
		threads.emplace_back([train]() -> void { train->arrival(); });
	}
	for (auto &thread: threads)
	{
		thread.join();
	}
	delete [] railwayStation;
	railwayStation = nullptr;
	return 0;
}
