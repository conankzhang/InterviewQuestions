#include "CircularList.h"

#include <cassert>

void InterviewQuestions::TestCircularList()
{
	Node* node1 = new Node();
	Node* node2 = new Node();
	Node* node3 = new Node();

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

bool InterviewQuestions::IsCircularLinkedList(const Node * i_pHead)
{
	assert(i_pHead);

	const Node * pSlowNode = i_pHead;
	const Node * pFastNode = i_pHead;

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
