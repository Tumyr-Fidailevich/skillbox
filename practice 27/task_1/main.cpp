#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>

#define TREE_DEEP 2
#define FOREST_SIZE 1

class Branch
{
private:
	Branch* _parent = nullptr;
	Branch* _childs = nullptr;
	int _childNumber = 0;
	std::string _memberName = "None";

	void _fillTree(int deep)
	{
		if (deep > 0)
		{
			_childNumber = (deep + 1) + std::rand() % (deep + 1);
			_childs = new Branch[_childNumber];
			for (int i = 0; i < _childNumber; i++)
			{
				_childs[i]._parent = this;
				std::cout << "Input name: ";
				std::cin >> _childs[i]._memberName;
				_childs[i]._fillTree(deep - 1);
			}
		}
	}

	Branch* _findBranch(std::string &name)
	{
		Branch* elfBranch = nullptr;
		if (_memberName == name)
		{
			elfBranch = this;
		} else
		{
			for (int i = 0; i < _childNumber; i++)
			{
				elfBranch = _childs[i]._findBranch(name);
				if(elfBranch != nullptr) break;
			}
		}
		return elfBranch;
	}

	static void _print(Branch &tree, int branchNumber)
	{
		for (int i = 0; i < tree._childNumber; i++)
		{
			if (tree._childs[i]._memberName != "None")
			{
				std::cout << "On (" << branchNumber << "," << i << ") branch lives " << tree._childs[i]._memberName
						  << std::endl;
			} else
			{
				std::cout << "On (" << branchNumber << "," << i << ") branch nobody lives" << std::endl;
			}
			_print(tree._childs[i], i);
		}
	}

public:

	~Branch()
	{
		delete[] _childs;
	}

	void fillTree()
	{
		assert(TREE_DEEP > 0);
		_childNumber = (TREE_DEEP + 1) + std::rand() % (TREE_DEEP + 1);
		_childs = new Branch[_childNumber];
		for (int i = 0; i < _childNumber; i++)
		{
			_childs[i]._parent = this;
			std::cout << "Input name: ";
			std::cin >> _childs[i]._memberName;
			_childs[i]._fillTree(TREE_DEEP - 1);
		}
	}

	int countNeighbours(std::string &name)
	{
		int count = 0;
		Branch* elfBranch = _findBranch(name);
		if (elfBranch == nullptr)
		{
			return 0;
		} else
		{
			if (elfBranch->_childNumber == 0)
			{
				Branch* parentBranch = elfBranch->_parent;
				for (int i = 0; i < parentBranch->_childNumber; i++)
				{
					if (parentBranch->_childs[i]._memberName != "None" && &parentBranch->_childs[i] != elfBranch)
					{
						count++;
					}
				}
				if (parentBranch->_memberName != "None") count++;
				return count;
			} else
			{
				for (int i = 0; i < elfBranch->_childNumber; i++)
				{
					if (elfBranch->_childs[i]._memberName != "None")
					{
						count++;
					}
				}
				return count;
			}
		}
	}

	static void print(Branch &tree)
	{
		for (int i = 0; i < tree._childNumber; i++)
		{
			if (tree._childs[i]._memberName != "None")
			{
				std::cout << "On " << i + 1 << " branch lives " << tree._childs[i]._memberName
						  << std::endl;
			} else
			{
				std::cout << "On " << i + 1 << " branch nobody lives" << std::endl;
			}
			_print(tree._childs[i], i + 1);
		}
	}

};

int main()
{
	const int forestSize = FOREST_SIZE;
	auto forest = new Branch[forestSize];
	for (int i = 0; i < forestSize; i++)
	{
		forest[i].fillTree();
	}
	for (int i = 0; i < forestSize; i++)
	{
		std::cout << i + 1 << "tree: " << std::endl;
		Branch::print(forest[i]);
	}
	std::string name;
	std::cout << "Input the name you are looking for: ";
	std::cin >> name;
	int count = 0;
	for (int i = 0; i < forestSize; i++)
	{
		count = forest[i].countNeighbours(name);
	}
	std::cout << name << " have " << count << " neighbours." << std::endl;
	delete[] forest;
	forest = nullptr;
	return 0;
}
