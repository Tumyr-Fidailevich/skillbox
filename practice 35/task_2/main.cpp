#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

auto makeUnique = [](std::vector<int> &arr) -> std::unique_ptr<std::vector<int>> {
	std::unordered_set<int> uniques;
	std::vector<int> result;
	for(auto &elem : arr)
	{
		if(uniques.insert(elem).second)
		{
			result.push_back(elem);
		}
	}
	return std::make_unique<std::vector<int>> (result.begin(), result.end());
};

void print(std::vector<int> &vec)
{
	for(auto &elem : vec)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5, 1, 4, 9, 0};
	print(vec);
	std::unique_ptr<std::vector<int>> ptr = makeUnique(vec);
	print(*ptr);
	return 0;
}
