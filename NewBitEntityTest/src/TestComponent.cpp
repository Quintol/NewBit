#include "TestComponent.h"
using namespace std;

void TestComponent::init()
{
	cout << "init:" << (void*)getEntity() << endl;
	has_init = true;
}

void TestComponent::destroy()
{
	cout << "destroy:" << (void*)getEntity() << endl;
}
