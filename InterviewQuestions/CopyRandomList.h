#pragma once

namespace InterviewQuestions
{
	struct RandomNode
	{
		RandomNode* m_pNext;
		RandomNode* m_pRandom;
		char m_Value;
	};

	void TestCopyRandomList();

	RandomNode* CopyRandomList(RandomNode* i_pHead);
}