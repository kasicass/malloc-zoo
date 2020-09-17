#pragma once

namespace MallocZoo {

MALLOCZOO_API void Init();
MALLOCZOO_API void Shutdown();

struct IMalloc
{
	virtual void* Malloc(size_t size) = 0;
	virtual void* Realloc(void* p, size_t size) = 0;
	virtual void Free(void* p) = 0;
};
extern MALLOCZOO_API IMalloc* theZoo;

}

#define FatMalloc(size)          MallocZoo::theZoo->Malloc(size)
#define FatRealloc(p, size)      MallocZoo::theZoo->Realloc(p, size)
#define FatFree(p)               MallocZoo::theZoo->Free(p)

#define FatNew(Type, ...)        new Type(__VA_ARGS__)
#define FatNewArray(Type, Count) new Type[Count]
#define FatDelete(Pointer)       delete Pointer
#define FatDeleteArray(Pointer)  delete [] Pointer
