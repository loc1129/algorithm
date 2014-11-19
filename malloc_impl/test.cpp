
#define HEAP_SIZE 1024
#define ALLIGNMENTSIZE 4

typedef struct MemBlock
{
	unsigned int size;
	unsigned int isFree;
} tMemBlock;

static void *gHeapBegin = NULL;
static void *gHeapEnd = gHeapBegin;
static bool isInitialized = false;

bool initMemBlock()
{
	if(isInitialized)
	{
		return true;
	}

	gHeapBegin = sbrk(HEAP_SIZE);
	if(gHeapBegin == NULL)
	{
		return false;
	}

	tMemBlock *pBlock = (tMemBlock*)(gHeapBegin);
	pBlock->size = HEAP_SIZE;
	pBlock->isFree = true;
	gHeapEnd = (void*)((char*)(gHeapBegin) + HEAP_SIZE - 1);

	isInitialized = true;
	return true;
}

void *mallocMem(size_t newSize)
{
	assert(isInitialized);
	tMemBlock * pPos = (tMemBlock*)gHeapBegin;
	while((void*)pPos != gHeapEnd)
	{
		if(!(pPos->isFree) ||  pPos->size < (newSize + sizeof(tMemBlock)))
		{
			pPos = (tMemBlock*)((char*)pPos + pPos->size); 
			continue;
		}

		if(pPos->size == (newSize + sizeof(tMemBlock)))
		{
			pPos->isFree = false;
			return (void*)((char*)pPos + sizeof(tMemBlock));
		}

		tMemBlock * pNewMemBlock = (char*)pPos + sizeof(tMemBlock) + newSize;
		pNewMemBlock->isFree = true;
		pNewMemBlock->size = pPos->size - newSize - sizeof(tMemBlock);

		pPos->size = newSize + sizeof(tMemBlock);
		pPos->isFree = false;
		return (void*)((char*)pPos + sizeof(tMemBlock));	
	}

	return NULL;
	
}

size_t allignment(size_t size, int allignmentSize)
{
	assert(allignmentSize % 2 == 0);

	return ((size + allignmentSize - 1) & (~(allignmentSize - 1)));
}

bool getMoreMemBlockFromSys(size_t size)
{
	assert(isInitialized);

	size_t newSize = allignment((size + sizeof(tMemBlock)), ALLIGNMENTSIZE);

	void *pBlock = sbrk(newSize);
	if(!pBlock)
	{
		return false;
	}

	tMemBlock * pMemBlock = (tMemBlock*)(pBlock);
	pMemBlock->size = newSize;
	pMemBlock->isFree = true;

	gHeapEnd = gHeapEnd + newSize - 1;
	return true;
}

void mergeMemBlock()
{	
	assert(isInitialized);
	tMemBlock * pPos = (tMemBlock*)gHeapBegin;
	while((void*)pPos != gHeapEnd)
	{
		tMemBlock * pNextPos = (tMemBlock*)((char*)pPos + pPos->size);
		if(pPos->isFree && pNextPos->isFree)
		{
			pPos->size = pPos->size + pNextPos->size;
		}

		pPos = (tMemBlock*)((char*)pPos + pPos->size);
	}
}

void *myMalloc(size_t size)
{
	if(!initMemBlock())
	{
		return NULL;
	}

	size_t sizeAfterAllignment = allignment(size, ALLIGNMENTSIZE); 
	void *pNewMem = mallocMem(sizeAfterAllignment); 
	if(pNewMem != NULL)
	{
		return pNewMem;
	}

	if(getMoreMemBlockFromSys(sizeAfterAllignment))
	{
		return mallocMem(sizeAfterAllignment);
	}
	else
	{
		mergeMemBlock();
		return mallocMem(sizeAfterAllignment);
	}
}
