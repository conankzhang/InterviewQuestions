#include "CopyRandomList.h"

#include <cassert>
#include <unordered_map>

void InterviewQuestions::TestCopyRandomList()
{
	RandomNode* node1 = new RandomNode();
	RandomNode* node2 = new RandomNode();
	RandomNode* node3 = new RandomNode();

	node1->m_pNext = node2;
	node2->m_pNext = node3;

	node1->m_Value = 'a';
	node2->m_Value = 'b';
	node3->m_Value = 'c';

	node1->m_pRandom = node3;
	node2->m_pRandom = node1;
	node3->m_pRandom = node2;

	RandomNode* copyListHead = CopyRandomList(node1);
	bool b = true;
}

InterviewQuestions::RandomNode* InterviewQuestions::CopyRandomList(RandomNode* i_pHead)
{
	RandomNode* copyHead = new RandomNode();
	RandomNode* currentCopy = copyHead;

	RandomNode* currentNode = i_pHead;
	RandomNode* nextNode = currentNode->m_pNext;

	std::unordered_map<RandomNode*, RandomNode*> randomNodes;
	randomNodes[currentNode] = copyHead;

	while (currentNode != nullptr)
	{
		currentCopy->m_Value = currentNode->m_Value;
		currentCopy->m_pRandom = currentNode->m_pRandom;

		if (nextNode != nullptr)
		{
			RandomNode* copyNode = new RandomNode();
			copyNode->m_Value = nextNode->m_Value;

			randomNodes[nextNode] = copyNode;

			currentCopy->m_pNext = copyNode;
			currentCopy = copyNode;

			currentNode = nextNode;
			nextNode = currentNode->m_pNext;
		}
		else
		{
			break;
		}
	}

	currentCopy = copyHead;
	while (currentCopy != nullptr)
	{
		RandomNode* randomCopyNode = randomNodes[currentCopy->m_pRandom];
		currentCopy->m_pRandom = randomCopyNode;

		currentCopy = currentCopy->m_pNext;
	}

	return copyHead;
}
