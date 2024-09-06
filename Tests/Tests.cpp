#include "pch.h"
#include "CppUnitTest.h"
#include "..\Domain\Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(GetSize_ValidData_Success)
		{
			// arrange
			Array a{ 1, 2, 3 };
			const size_t expected = 3;
			// act
			auto actual = a.Size();
			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Ctor_NegativeSize_ExpectedException)
		{
			Assert::ExpectException<std::logic_error>([]() {auto a = new Array(0); });
		}

		TEST_METHOD(CopyCtor_Success)
		{
			// arrange
			Array array{ 1, 2, 3 };

			// act
			Array copy(array);
			array[0] = 0;

			// assert
			Assert::AreNotEqual(array, copy);
		}
	};
}
