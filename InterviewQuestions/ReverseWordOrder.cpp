#include "ReverseWordOrder.h"

#include <cassert>
#include <stack>

void InterviewQuestions::TestReverseWordOrder()
{
	std::string test = "This is a sentence.";
	std::string reverseTest = ReverseWordOrder(test);

	assert(reverseTest == "sentence. a is This");
}

std::string InterviewQuestions::ReverseWordOrder(const std::string& i_string)
{
	std::string reverseString;
	reverseString.reserve(i_string.length());

	std::stack<char> characters;

	for (int i = i_string.length() - 1; i >= 0; i--)
	{
		if (i_string[i] != ' ')
		{
			characters.push(i_string[i]);
		}
		else
		{
			while (!characters.empty())
			{
				reverseString.push_back(characters.top());
				characters.pop();
			}

			reverseString.push_back(' ');
		}
	}

	while (!characters.empty())
	{
		reverseString.push_back(characters.top());
		characters.pop();
	}

	return reverseString;
}
