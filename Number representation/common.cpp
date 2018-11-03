#include "common.h"

int intFromBinary(const std::string &number)
{
	int ret = 0;

	unsigned int i = 0;
	unsigned int length = number.length();

	while (number[i] && i < length)
	{
		ret <<= 1;
		if (number[i] == '1')
		{
			ret++;
		}
		i++;
	}

	return ret;
}

std::string binaryFromInt(int x)
{
	std::string ret = "";

	unsigned int mask = 0x80000000;

	for (size_t i = 0; i < 32; i++)
	{
		if (x & mask)
		{
			ret += "1";
		}
		else /*if (ret != "")*/
		{
			ret += "0";
		}
		mask >>= 1;
	}

	return ret;
}

void printIntAsBinary(int x)
{
	std::string str = binaryFromInt(x);
	printf("%s\n", str.c_str());
}

std::string binaryFromChar(char x)
{
	std::string ret = "";

	unsigned int mask = 0x80;

	for (size_t i = 0; i < 8; i++)
	{
		if (x & mask)
		{
			ret += "1";
		}
		else /*if (ret != "")*/
		{
			ret += "0";
		}
		mask >>= 1;
	}

	return ret;
}

void printCharAsBinary(char x)
{
	std::string str = binaryFromChar(x);
	printf("%s\n", str.c_str());
}