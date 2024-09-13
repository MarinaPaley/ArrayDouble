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

		TEST_METHOD(CopyAssignDifferentArrays_Success)
		{
			// arrange
			Array array{ 1, 2, 3 };
			Array copy{ 3, 5, 8 };

			// act
			copy = array;

			// assert
			Assert::AreEqual(array, copy);
		}

		TEST_METHOD(CopyAssignSameArrays_Success)
		{
			// arrange
			Array array{ 1, 2, 3 };
			Array copy{ 1, 2, 3 };

			// act
			copy = array;
			array[0] = 0;

			// assert
			Assert::AreNotEqual(array, copy);
		}

		TEST_METHOD(MoveCtor_Success)
		{
			// arrange
			Array array{ 1, 2, 3 };
			const size_t size = 3;

			// act
			Array move(std::move(array));

			// assert
			Assert::AreEqual(size, move.Size());
		}

		TEST_METHOD(MoveAssign_Success)
		{
			// arrange
			Array array{ 1, 2, 3 };
			Array move{ 3 };
			const size_t size = 3;

			// act
			move = std::move(array);

			// assert
			Assert::AreEqual(size, move.Size());
		}

		TEST_METHOD(OperatorSubscript_ValidIndex_Success)
		{
			// arrange
			Array array{ 1, 2, 3 };
			auto expected = 2;

			// act
			auto actual = array[1];

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(OperatorSubscript_WrongIndex_ExpectedException)
		{
			// arrange
			Array array{ 1, 2, 3 };

			//act & assert
			Assert::ExpectException<std::out_of_range>([&]() { auto i = array[4]; });
		}

		TEST_METHOD(ToString_Success)
		{
			// arrange
			Array array{ 1, 2, 3 };
			const std::string expected = "1 2 3 ";

			// act
			const auto actual = array.ToString();

			// assert
			Assert::AreEqual(expected, actual);
		}
	};
}
