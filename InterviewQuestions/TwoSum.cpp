#include "TwoSum.h"
#include <assert.h>

void InterviewQuestions::TestTwoSum()
{
	int Array1[6] = { -1, 3, 8, 2, 9, 5 };
	int Array2[6] = { 4, 1, 2, 10, 5, 20 };

	std::pair<int, int> Result = TwoSum(Array1, Array2, 6, 24);
	assert(Result.first == 3 && Result.second == 20);
}

std::pair<int, int> InterviewQuestions::TwoSum(const int Array1[], const int Array2[], int Size, int Target)
{
	// Handle Case where Size is Not Equal to Size of Arrays

	std::pair<int, int> ResultPair;

	ResultPair.first = 0;
	ResultPair.second = 0;

	int BestTargetSoFar = Array1[0] + Array2[0];
	int TargetSoFar = 0;

	for (int i = 0; i < Size; i++)
	{
		int FirstInt = Array1[i];

		for (int j = 0; j < Size; j++)
		{
			int SecondInt = Array2[j];

			TargetSoFar = FirstInt + SecondInt;

			if (abs((Target - TargetSoFar)) < abs(Target - BestTargetSoFar))
			{
				BestTargetSoFar = TargetSoFar;

				ResultPair.first = FirstInt;
				ResultPair.second = SecondInt;
			}
		}
	}

	return ResultPair;
}
