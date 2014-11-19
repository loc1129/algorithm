#include <tr1/unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct BucketType
{
	int bindex;
	int size;
} tBucketType;

struct mycompareFunc
{
	bool operator()(tBucketType i, tBucketType j)
	{
		return i.size < j.size;
	}
};

int main()
{
	const int src_size = 5;
	int src[5] = {1,100,2,200,2};

	tr1::unordered_multimap<int, int> mymap;

	for(int index = 0; index < src_size; ++index)
	{
		mymap.insert(make_pair<int, int>(src[index], src[index]));
	}

	unsigned int bucket_count = mymap.bucket_count(); 

	vector<tBucketType> buckets;
	for(int index = 0; index < bucket_count; ++index)
	{
		tBucketType element;
		element.bindex = index;
		element.size = mymap.bucket_size(index);
		buckets.push_back(element);
	}

	struct mycompareFunc mycompareFuncObj;
	sort(buckets.begin(), buckets.end(), mycompareFuncObj);
	
	for(int index = 0; index < bucket_count; ++index)
	{
		tr1::unordered_multimap<int, int>::local_iterator local_it = mymap.begin(buckets[index].bindex);
		for( ; local_it != mymap.end(buckets[index].bindex); ++ local_it)
		{
			cout << " " << local_it->second;
		}
	}
	cout << endl;

	return 0;
}
