#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.4 pek.cpp"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64pek
{
	TEST_CLASS(UnitTest64pek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TEST(ArrayTest, SumBeforeLastPositiveTest) {
				double arr[] = { -3.5, 4.2, 1.8, -7.9, 6.4 };
				EXPECT_DOUBLE_EQ(SumBeforeLastPositive(arr, 5), -5.4);
		}
	};
}
