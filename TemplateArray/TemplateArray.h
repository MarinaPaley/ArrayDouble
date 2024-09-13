#pragma once

#include <sstream>


namespace miit
{
	template<typename T> class TemplateArray;

	template<typename T>
	bool operator==(const TemplateArray<T>& lha, const TemplateArray<T>& rha);

	template<typename T>
	std::wstring ToString(const TemplateArray<T>& array);

	template<typename T>
	class TemplateArray final
	{
	private:
		size_t size;
		T* data;
		void CheckIndex(const size_t index) const;
	public:
		explicit TemplateArray(const int size);
		TemplateArray(std::initializer_list<T> list);
		~TemplateArray();
		TemplateArray(const TemplateArray& other);
		TemplateArray(TemplateArray&& other) noexcept;
		TemplateArray& operator=(const TemplateArray& other);
		TemplateArray& operator=(TemplateArray&& other) noexcept;
		size_t Size() const;
		T& operator[](size_t index);
		const T operator[](size_t index) const;
		std::string ToString() const noexcept;
	};


	template<typename T>
	inline void TemplateArray<T>::CheckIndex(const size_t index) const
	{
		if (this->size < index)
		{
			throw std::out_of_range("Выход за границы массива");
		}
	}

	template<typename T>
	inline TemplateArray<T>::TemplateArray(const int size)
	{
		if (size <= 0)
		{
			throw std::invalid_argument("Размер строго больше 0!");
		}

		this->size = static_cast<size_t>(size);
		this->data = new T[this->size];
	}

	template<typename T>
	inline TemplateArray<T>::TemplateArray(std::initializer_list<T> list)
		:size{ list.size() }, data{ new T[this->size] }
	{
		std::copy(list.begin(), list.end(), this->data);
	}

	template<typename T>
	inline TemplateArray<T>::~TemplateArray()
	{
		delete[] this->data;
	}

	template<typename T>
	inline TemplateArray<T>::TemplateArray(const TemplateArray& other)
		:size{ other.size }, data{ new T[this->size] }
	{
		std::copy(other.data, other.data + other.size, this->data);
	}

	template<typename T>
	inline TemplateArray<T>::TemplateArray(TemplateArray&& other) noexcept
		:size{ 0 }, data{ nullptr }
	{
		*this = std::move(other);
	}

	template<typename T>
	inline TemplateArray<T>& TemplateArray<T>::operator=(const TemplateArray<T>& other)
	{
		if (this != &other)
		{
			TemplateArray<T> temp(other);

			std::swap(this->size, temp.size);
			std::swap(this->data, temp.data);
		}

		return *this;
	}

	template<typename T>
	inline TemplateArray<T>& TemplateArray<T>::operator=(TemplateArray<T>&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(this->size, other.size);
			std::swap(this->data, other.data);
		}
		return *this;
	}

	template<typename T>
	inline size_t TemplateArray<T>::Size() const
	{
		return this->size;
	}

	template<typename T>
	inline T& TemplateArray<T>::operator[](size_t index)
	{
		this->CheckIndex(index);
		return this->data[index];
	}

	template<typename T>
	inline const T TemplateArray<T>::operator[](size_t index) const
	{
		this->CheckIndex(index);
		return this->data[index];
	}

	template<typename T>
	inline std::string TemplateArray<T>::ToString() const noexcept
	{
		std::stringstream buffer{};
		for (auto i = 0; i < this->size; ++i)
		{
			buffer << this->data[i] << " ";
		}

		return buffer.str();
	}

	template<typename T>
	bool operator==(const TemplateArray<T>& lha, const TemplateArray<T>& rha)
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

	template<typename T>
	std::wstring ToString(const TemplateArray<T>& array)
	{
		std::wstringstream buffer{};
		for (auto i = 0; i < array.Size(); ++i)
		{
			buffer << array[i] << L" ";
		}

		return buffer.str();
	}

}