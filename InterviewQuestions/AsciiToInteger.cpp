#include "AsciiToInteger.h"
#include <cassert>

void InterviewQuestions::TestAsciiToInteger()
{
	int integer = atoi("125");
	assert(integer == 125);

	integer = atoi("531532");
	assert(integer == 531532);

	integer = atoi("-8120");
	assert(integer == -8120);
}

int InterviewQuestions::atoi(const char * i_string)
{
	int integer = 0;

	bool isNegative = false;
	if (*i_string == '-')
	{
		isNegative = true;
		i_string++;
	}

	while (*i_string != '\0')
	{
		integer *= 10;
		integer += *i_string - '0';
		i_string++;
	}

	if (isNegative)
	{
		integer = -integer;
	}

	return integer;
}
