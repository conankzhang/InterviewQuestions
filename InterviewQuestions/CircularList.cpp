#include "CircularList.h"

#include <cassert>

void InterviewQuestions::TestCircularList()
{
	CircularNode* node1 = new CircularNode();
	CircularNode* node2 = new CircularNode();
	CircularNode* node3 = new CircularNode();

	node1->m_pNext = node2;
	node2->m_pNext = node3;
	node3->m_pNext = node2;

	bool detectedCircularList = IsCircularLinkedList(node1);
	assert(detectedCircularList);

	node3->m_pNext = nullptr;

	bool detectedNonCircularList = !IsCircularLinkedList(node1);
	assert(detectedNonCircularList);

	delete node1;
	delete node2;
	delete node3;
}

bool InterviewQuestions::IsCircularLinkedList(const CircularNode * i_pHead)
{
	assert(i_pHead);

	const CircularNode * pSlowNode = i_pHead;
	const CircularNode * pFastNode = i_pHead;

	while (pSlowNode->m_pNext)
	{
		pSlowNode = pSlowNode->m_pNext;

		pFastNode = pFastNode->m_pNext;
		if (pFastNode && pFastNode->m_pNext)
		{
			pFastNode = pFastNode->m_pNext;
		}
		if (pSlowNode == pFastNode)
		{
			return true;
		}
	}

	return false;
}
