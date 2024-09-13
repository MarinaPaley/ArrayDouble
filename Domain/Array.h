#pragma once
#include <initializer_list>

namespace miit 
{
	class Array;
	bool operator==(const Array& lha, const Array& rha);
	std::wstring ToString(const Array& array);

	class Array final
	{
	private:
		size_t size;
		int* data;
		void CheckIndex(const size_t index) const;
	public:
		explicit Array(const int size);
		Array(std::initializer_list<int> list);
		~Array();
		Array(const Array& other);
		Array(Array&& other) noexcept;
		Array& operator=(const Array& other);
		Array& operator=(Array&& other) noexcept;
		size_t Size() const;
		int& operator[](size_t index);
		const int operator[](size_t index) const;
		std::string ToString() const noexcept;
	};
}