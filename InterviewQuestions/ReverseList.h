#pragma once

namespace InterviewQuestions
{
	struct Node;

	void TestReverseList();

	void ReverseLinkedList(Node *& i_pHead);
	bool IsLinkedListReversed(const Node * i_pHead, const char * i_pReversedValue);
}