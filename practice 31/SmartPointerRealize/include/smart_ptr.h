#pragma once
#include <string>
#include <cstddef>

template<typename T>
class shared_ptr
{
private:
	T* _obj;
	int* _count;

	void update()
	{
		if (_obj != nullptr && _count != nullptr)
		{
			(*_count)--;
			if (*_count == 0)
			{
				delete _obj;
				delete _count;
			}
		}
	}

public:
	//For lvalue reference
	explicit shared_ptr(const T &obj) : _obj(new T(obj)), _count(new int(1))
	{}

	//For rvalue reference
	explicit shared_ptr(const T &&obj) : _obj(new T(obj)), _count(new int(1))
	{}

	shared_ptr() : _obj(nullptr), _count(nullptr)
	{};

	shared_ptr<T> &operator=(const shared_ptr<T> &other)
	{
		if (this != &other)
		{
			update();
			_obj = other._obj;
			_count = other._count;
			if (_count != nullptr) (*_count)++;
		}
		return *this;
	}

	shared_ptr<T> &operator=(std::nullptr_t)
	{
		update();
		_obj = nullptr;
		_count = nullptr;
		return *this;
	}

	T &operator*() const
	{
		return *_obj;
	}

	T* operator->() const
	{
		return _obj;
	}

	bool operator==(const shared_ptr<T> &other) const
	{
		return _obj == other._obj;
	}

	bool operator!=(const shared_ptr<T> &other) const
	{
		return !(*this == other);
	}

	bool operator==(std::nullptr_t) const
	{
		return _obj == nullptr;
	}

	bool operator!=(std::nullptr_t) const
	{
		return _obj != nullptr;
	}

	~shared_ptr()
	{
		update();
	}

	int use_count() const
	{
		return *_count;
	}
};

template<typename T>
shared_ptr<T> make_shared(const std::string &name)
{
	return shared_ptr<T>(T(name));
}

template<typename T>
shared_ptr<T> make_shared(const T &obj)
{
	return shared_ptr<T>(obj);
}
