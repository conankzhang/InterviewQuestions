#pragma once

namespace InterviewQuestions
{
	struct ReverseNode
	{
		ReverseNode * m_pNext;
		char m_Value;
	};

	void TestReverseList();

	void ReverseLinkedList(ReverseNode *& i_pHead);
	bool IsLinkedListReversed(const ReverseNode * i_pHead, const char * i_pReversedValue);
}
