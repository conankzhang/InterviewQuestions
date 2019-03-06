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

	void CopyRandomList(RandomNode* i_pHead);
}