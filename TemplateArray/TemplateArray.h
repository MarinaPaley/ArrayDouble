#pragma once
namespace miit
{
	template<typename T>
	class TemplateArray final
	{
	private:
		size_t size;
		T* data;
		//void CheckIndex(const size_t index) const;
	public:
		explicit TemplateArray(const int size);
		TemplateArray(std::initializer_list<T> list);
		~TemplateArray();
		//TemplateArray(const TemplateArray& other);
		//TemplateArray(TemplateArray&& other) noexcept;
		//TemplateArray& operator=(const TemplateArray& other);
		//TemplateArray& operator=(TemplateArray&& other) noexcept;
		//size_t Size() const;
		//int& operator[](size_t index);
		//const int operator[](size_t index) const;
		//std::string ToString() const noexcept;
	};


	template<typename T>
	inline TemplateArray<T>::TemplateArray(const int size)
	{
		if (size <= 0)
		{
			throw std::invalid_argument("Размер строго больше 0!");
		}

		this->size = static_cast<size_t>(size);
		this->data = new int[this->size];
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

}