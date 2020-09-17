#include "MallocZoo.h"
#include "MzNewDelete.h"

void MallocMe()
{
	void* p = FatMalloc(10);
}

class MyClass
{
private:
	int value;
};

int main()
{
	MallocZoo::Init();

	MallocMe();
	MallocMe();

	MyClass* c = FatNew(MyClass);
	FatDelete(c);

	MallocZoo::Shutdown();
	return 0;
}
