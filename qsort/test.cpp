#include <iostream>
#include <assert.h>

int ajust(int* src, int begin, int end)
{
	assert(begin < end);
	assert(src != NULL);

	int central = *(src + begin);
	int i = begin;
	int j = end;
	while(true)
	{
		for(; i <= end && *(src + i) <= central; ++i);
		for(; j >= begin && *(src + j) > central; --j);
		if(i < j)
		{
			int temp = *(src+i);
			*(src+i) = *(src+j);
			*(src+j) = temp;
		}
		else
		{
			break;
		}
	}

	*(src + begin) = *(src + j);
	*(src + j) = central;
	return j;
}

void qsort(int *src, int begin, int end)
{
	if(src == NULL)
	{
		return;
	}

	if(begin >= end)
	{
		return;
	}

	int ret = ajust(src, begin, end);
	qsort(src, begin, (ret - 1));
	qsort(src, (ret + 1), end);
}

int main()
{
	//int src[10] = {4,6,2,1,9,10,5,7,3,8};
	//int src[10] = {1,2,3,4,5,6,7,8,9,10};
	//int src[10] = {10,9,8,7,6,5,4,3,2,1};
	int src[10] = {10,9,8,8,6,4,4,3,2,1};

	for(int i = 0; i < 10; ++i)
	{
		std::cout<<" "<<*(src+i);
	}
	std::cout<<std::endl;

	qsort(src, 0, 9);

	for(int i = 0; i < 10; ++i)
	{
		std::cout<<" "<<*(src+i);
	}
	std::cout<<std::endl;
}

