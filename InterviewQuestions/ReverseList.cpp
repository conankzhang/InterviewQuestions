#include "ReverseList.h"
#include "CircularList.h"

#include <cassert>

void InterviewQuestions::TestReverseList()
{
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();

	node1->m_pNext = node2;
	node2->m_pNext = node3;

	node1->m_Value = 'a';
	node2->m_Value = 'b';
	node3->m_Value = 'c';

	const char * reversedValues = "cba";
	ReverseLinkedList(node1);

	bool isLinkedListReversed = IsLinkedListReversed(node1, reversedValues);
	assert(isLinkedListReversed);
}

void InterviewQuestions::ReverseLinkedList(Node *& i_pHead)
{
	assert(i_pHead);

	Node * pPrevious = i_pHead;
	Node * pCurrent = i_pHead->m_pNext;
	Node * pNext = nullptr;

	i_pHead->m_pNext = nullptr;

	while (pCurrent)
	{
		pNext = pCurrent->m_pNext;
		pCurrent->m_pNext = pPrevious;
		pPrevious = pCurrent;
		pCurrent = pNext;
	}

	i_pHead = pPrevious;
}

bool InterviewQuestions::IsLinkedListReversed(const Node * i_pHead, const char * i_pReversedValue)
{
	assert(i_pHead && i_pReversedValue);

	while (i_pHead)
	{
		if (i_pHead->m_Value != *i_pReversedValue)
		{
			return false;
		}

		i_pHead = i_pHead->m_pNext;
		i_pReversedValue++;
	}

	return true;
}
