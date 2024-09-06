#pragma once
#include <initializer_list>
class Array final
{
private:
	size_t size;
	int* data;
public:
	explicit Array(int size);
	Array(std::initializer_list<int> list);
	~Array();
	Array(const Array& other);
	Array(Array&& other);
	Array& operator=(const Array& other);
	Array& operator=(Array&& other);
	size_t Size() const;
	int& operator[](size_t index);
	const int operator[](size_t index) const;
};