#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cstdlib>
#include <queue>
#include <condition_variable>

#define MAX_ORDERS_COUNT 10
const std::string dishes[5] = {"pizza", "soup", "steak", "salad", "sushi"};

class Order
{
private:
	int _cookTime = 5 + std::rand() % 11;
	std::string _dish;
public:
	explicit Order(int number)
	{
		_dish = dishes[std::rand() % 5] + std::to_string(number);
	}
	std::string getDish() const
	{
		return _dish;
	}

	int getCookTime() const
	{
		return _cookTime;
	}

};
std::mutex kitchenMutex;
std::mutex globalMutex;
std::queue<Order> orders;
std::vector<Order> readyOrders;
std::condition_variable kitchenCV;
bool isKitchenBusy = false;

void cooking()
{

	std::unique_lock<std::mutex> lock(kitchenMutex);
	kitchenCV.wait(lock, [] { return !isKitchenBusy; });
	globalMutex.lock();
	isKitchenBusy = true;
	Order order = orders.front();
	std::cout << "Kitchen started cooking " << order.getDish() << std::endl;
	globalMutex.unlock();
	{
		std::this_thread::sleep_for(std::chrono::seconds(order.getCookTime()));
		std::lock_guard<std::mutex> lockGuard(globalMutex);
		isKitchenBusy = false;
		std::cout << "Order with " << order.getDish() << " ready for delivery" << std::endl;
		readyOrders.push_back(order);
		orders.pop();
	}
}

void delivery()
{
	int deliveryCount = 0;
	while (deliveryCount < MAX_ORDERS_COUNT)
	{
		std::this_thread::sleep_for(std::chrono::seconds(30));
		{
			std::lock_guard<std::mutex> lockGuard(globalMutex);
			for (auto &order: readyOrders)
			{
				std::cout << order.getDish() << " sent to the customer" << std::endl;
				deliveryCount++;
			}
			readyOrders.clear();
		}
	}
}

int main()
{
	std::vector<std::thread> ordersThread;
	std::thread deliveryThread(delivery);
	for (int i = 0; i < MAX_ORDERS_COUNT; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(5 + std::rand() % 6));
		std::lock_guard<std::mutex> lockGuard(globalMutex);
		orders.emplace(i);
		std::cout << "Order with " << orders.back().getDish() << " entered the kitchen" << std::endl;
		ordersThread.emplace_back(cooking);
	}
	for (auto &thread: ordersThread)
	{
		thread.join();
	}
	deliveryThread.join();
	std::cout << "The kitchen is finished" << std::endl;
	return 0;
}
