#pragma once

namespace InterviewQuestions
{
	struct CircularNode
	{
		CircularNode * m_pNext;
		char m_Value;
	};

	void TestCircularList();
	bool IsCircularLinkedList(const CircularNode * i_pHead);
}