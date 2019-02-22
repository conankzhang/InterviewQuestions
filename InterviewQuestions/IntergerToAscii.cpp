#include "IntergerToAscii.h"
#include "StringCompare.h"
#include <assert.h>

void TestIntegerToAscii()
{
	char buffer[50];

	const char * ascii = itoa(125, buffer, 10);
	assert( strcmp(ascii, "125") == 0);

	ascii = itoa(5321, buffer, 10);
	assert( strcmp(ascii, "5321") == 0);

	ascii = itoa(-800329, buffer, 10);
	assert( strcmp(ascii, "-800329") == 0);
}

const char * itoa(int i_int, char * i_buffer, int i_base)
{
	i_buffer[0] = '\0';

	bool isNegative = false;
	if (i_int < 0)
	{
		isNegative = true;
		i_int = -i_int;
	}

	int digit = 1;
	while (i_int > 0)
	{
		int remaining = i_int % i_base;

		if (remaining > 9)
		{
			i_buffer[digit] = (remaining - 10) + 'A';
		}
		else
		{
			i_buffer[digit] = remaining + '0';
		}

		i_int /= i_base;
		digit++;
	}

	if (isNegative)
	{
		i_buffer[digit++] = '-';
	}

	return reverse(i_buffer, digit);
}

char * reverse(char * i_buffer, int i_length)
{
	int start = 0;
	int end = i_length - 1;

	while (start < end)
	{
		char temp = i_buffer[start];
		i_buffer[start] = i_buffer[end];
		i_buffer[end] = temp;
		start++;
		end--;
	}

	return i_buffer;
}
