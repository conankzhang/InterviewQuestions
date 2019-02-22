#include "StringCompare.h"

#include <stdio.h>
#include <assert.h>

void TestStringCompare()
{
	const char * lhs = "left";
	const char * rhs = "left";

	int result = strcmp(lhs, rhs);
	assert(result == 0);

	rhs = "right";
	result = strcmp(lhs, rhs);
	assert(result < 0);

	lhs = "right";
	rhs = "left";

	result = strcmp(lhs, rhs);
	assert(result > 0);

	getchar();
}

int strcmp(const char * i_lhs, const char * i_rhs)
{
	assert(i_lhs && i_rhs);

	while (*i_lhs != '\0' && *i_lhs == *i_rhs)
	{
		i_lhs++;
		i_rhs++;
	}

	return *i_lhs - *i_rhs;
}
