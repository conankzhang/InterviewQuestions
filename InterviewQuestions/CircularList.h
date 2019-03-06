#pragma once

namespace InterviewQuestions
{
	struct Node
	{
		Node * m_pNext;
		char m_Value;
	};

	void TestCircularList();
	bool IsCircularLinkedList(const Node * i_pHead);
}