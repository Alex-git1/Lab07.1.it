#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab07.1(it)/Lab07.1(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** Z = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				Z[i] = new int[colCount];

			Z[0][0] = 2; Z[0][1] = 3; Z[0][2] = 4;
			Z[1][0] = 5; Z[1][1] = 6; Z[1][2] = 7;
			Z[2][0] = 8; Z[2][1] = 9; Z[2][2] = 10;

			int expectedSum = 24; 
			int expectedCount = 4; 
			int expectedMatrix[3][3] = {
				{0, 3, 0},
				{5, 6, 7},
				{0, 9, 0}
			};

			int S = 0;
			int k = 0;

			Calc(Z, rowCount, colCount, S, k);

			Assert::AreEqual(expectedSum, S);
			Assert::AreEqual(expectedCount, k);

			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					Assert::AreEqual(expectedMatrix[i][j], Z[i][j]);
				}
			}

			for (int i = 0; i < rowCount; i++)
				delete[] Z[i];
			delete[] Z;
		}
	};
}
