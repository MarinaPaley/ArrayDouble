#include "pch.h"
#include "CppUnitTest.h"
#include "..\TemplateArray\TemplateArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:

		TEST_METHOD(GetSizeIntArray_ValidData_Success)
		{
			// arrange
			TemplateArray<int> a{ 1, 2, 3 };
			const size_t expected = 3;
			// act
			auto actual = a.Size();
			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetSizeStringArray_ValidData_Success)
		{
			// arrange
			TemplateArray<std::string> a{ "1", "2", "3" };
			const size_t expected = 3;
			// act
			auto actual = a.Size();
			// assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CtorInt_NegativeSize_ExpectedException)
		{
			Assert::ExpectException<std::logic_error>(
				[]() {auto a = new TemplateArray<int>(0); });
		}

		TEST_METHOD(CtorString_NegativeSize_ExpectedException)
		{
			Assert::ExpectException<std::logic_error>(
				[]() {auto a = new TemplateArray<std::string>(0); });
		}

		TEST_METHOD(CopyCtorInt_Success)
		{
			// arrange
			TemplateArray<int> array{ 1, 2, 3 };

			// act
			TemplateArray<int> copy(array);
			array[0] = 0;

			// assert
			Assert::AreNotEqual(array, copy);
		}

		TEST_METHOD(CopyCtorString_Success)
		{
			// arrange
			TemplateArray<std::string> array{ "1", "2", "3" };

			// act
			TemplateArray<std::string> copy(array);
			array[0] = "0";

			// assert
			Assert::AreNotEqual(array.ToString(), copy.ToString());
		}
	};
}