#include <iostream>
#include <assert.h>

void rotate(char *src, int len)
{
	char *pBegin = src;
	char *pEnd = src + len - 1;

	while(pBegin < pEnd)
	{
		char temp;
		temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		++pBegin;
		--pEnd;
	}
}

bool shift_right_n(char *src, int len, int n)
{
	if(n > len)
	{
		return false;
	}

	rotate(src, n);
	rotate(src + n, len - n);
	rotate(src, len);

	return true;
}

int main()
{
	int i = 0;
	//int len = 10;
	//char src[10] = {'a','b','c','d','e','f','h','i','j','k'};
	int len = 11;
	char src[11] = {'a','b','c','d','e','f','h','i','j','k','l'};

	for(i = 0; i < len; ++i)
	{
		std::cout << " " << *(src + i);
	}
	std::cout << std::endl;

	bool ret = shift_right_n(src, len, 2);
	assert(ret);

	for(i = 0; i < len; ++i)
	{
		std::cout << " " << *(src + i);
	}
	std::cout << std::endl;

	return 0;
}
