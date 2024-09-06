#include <stdexcept>
#include <sstream>

#include "Array.h"

namespace miit
{
	void Array::CheckIndex(const size_t index) const
	{
		if (this->size < index)
		{
			throw std::out_of_range("Выход за границы массива");
		}
	}

	Array::Array(const int size)
	{
		if (size <= 0)
		{
			throw std::invalid_argument("Размер строго больше 0!");
		}

		this->size = static_cast<size_t>(size);
		this->data = new int[this->size];
	}

	Array::Array(std::initializer_list<int> list)
		:size{ list.size() }, data{ new int[this->size] }
	{
		std::copy(list.begin(), list.end(), this->data);
	}

	Array::~Array()
	{
		delete[] this->data;
	}

	Array::Array(const Array& other)
		:size{ other.size }, data{ new int[this->size] }
	{
		std::copy(other.data, other.data + other.size, this->data);
	}

	Array::Array(Array&& other) noexcept
		:size{ 0 }, data{ nullptr }
	{
		*this = std::move(other);
	}


	Array& Array::operator=(const Array& other)
	{
		if (this != &other)
		{
			Array temp(other);

			std::swap(this->size, temp.size);
			std::swap(this->data, temp.data);
		}

		return *this;
	}


	Array& Array::operator=(Array&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(this->size, other.size);
			std::swap(this->data, other.data);
		}
		return *this;
	}

	size_t Array::Size() const
	{
		return this->size;
	}

	int& Array::operator[](size_t index)
	{
		this->CheckIndex(index);
		return this->data[index];
	}

	const int Array::operator[](size_t index) const
	{
		this->CheckIndex(index);
		return this->data[index];
	}

	std::string Array::ToString() const noexcept
	{
		std::stringstream buffer{};
		for (auto i = 0; i < this->size; ++i)
		{
			buffer << this->data[i] << " ";
		}

		return buffer.str();
	}

	bool miit::operator==(const Array& lha, const Array& rha)
	{
		if (lha.Size() != rha.Size())
		{
			return false;
		}
		for (auto i = 0; i < lha.Size(); ++i)
		{
			if (lha[i] != rha[i])
			{
				return false;
			}
		}

		return true;
	}
	std::wstring ToString(const Array& array)
	{
		std::wstringstream buffer{};
		for (auto i = 0; i < array.Size(); ++i)
		{
			buffer << array[i] << " ";
		}

		return buffer.str();
	}
}