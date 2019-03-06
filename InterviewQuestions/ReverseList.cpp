#include "ReverseList.h"
#include "CircularList.h"

#include <cassert>

void InterviewQuestions::TestReverseList()
{
	ReverseNode* node1 = new ReverseNode();
	ReverseNode* node2 = new ReverseNode();
	ReverseNode* node3 = new ReverseNode();

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

void InterviewQuestions::ReverseLinkedList(ReverseNode *& i_pHead)
{
	assert(i_pHead);

	ReverseNode * pPrevious = i_pHead;
	ReverseNode * pCurrent = i_pHead->m_pNext;
	ReverseNode * pNext = nullptr;

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

bool InterviewQuestions::IsLinkedListReversed(const ReverseNode * i_pHead, const char * i_pReversedValue)
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
