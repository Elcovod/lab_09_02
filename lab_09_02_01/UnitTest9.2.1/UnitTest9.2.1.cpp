#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_09_02_01\lab_09_02_01\macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Macros
{
	TEST_CLASS(MacroTests)
	{
	public:

		TEST_METHOD(Test_Macro_MAX)
		{
			Assert::AreEqual(10, MAX(5, 10));
			Assert::AreEqual(20, MAX(20, 1));
			Assert::AreEqual(5, MAX(5, 5));
		}

		TEST_METHOD(Test_Macro_MIN)
		{
			Assert::AreEqual(5, MIN(5, 10));
			Assert::AreEqual(-5, MIN(0, -5));
		}

		TEST_METHOD(Test_Macro_POW)
		{
			double result = POW(2, 3);
			Assert::AreEqual(8.0, result, 0.0001);

			result = POW(5, 2);
			Assert::AreEqual(25.0, result, 0.0001);
		}

		TEST_METHOD(Test_Macro_IS_GREATER)
		{
			Assert::IsTrue(IS_GREATER(10, 5));
			Assert::IsFalse(IS_GREATER(3, 5));
		}

		TEST_METHOD(Test_Logic_Branch_Z_Greater_3)
		{
			int x = 5;
			int y = 2;
			int z = 4;

			int expected_w = 3;
			int actual_w = (int)MAX(POW((x - z), 2), x - y);

			Assert::AreEqual(expected_w, actual_w);
		}

		TEST_METHOD(Test_Logic_Branch_Z_LessEqual_3)
		{
			int x = 2;
			int y = 3;
			int z = 2;

			int expected_w = 12;

			int xy = x * y;
			int yz = y * z;
			int zx = z * x;

			int actual_w = MAX(xy, yz) + MAX(zx, yz);

			Assert::AreEqual(expected_w, actual_w);
		}
	};
}