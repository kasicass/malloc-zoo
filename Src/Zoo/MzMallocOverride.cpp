#include "MallocZoo.h"
#include <stdlib.h>
#include <stdio.h>

namespace MallocZoo {

void Init()
{
}

void Shutdown()
{
}

class MallocImp : public IMalloc
{
public:
	virtual void* Malloc(size_t size) override;
	virtual void* Realloc(void* p, size_t size) override;
	virtual void Free(void* p) override;
};
static MallocImp s_myMallocImp;
IMalloc* theZoo = &s_myMallocImp;

void* MallocImp::Malloc(size_t size)
{
	return malloc(size);
}

void* MallocImp::Realloc(void* p, size_t size)
{
	return realloc(p, size);
}

void MallocImp::Free(void* p)
{
	return free(p);
}

}
