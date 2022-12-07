#include "Count.h"

using namespace std;


Count::Count()
{
	num = 0;
}

void Count::add()
{
	num += 1 + (num / 1000) + 1;
}

void Count::add2()
{
	num += 2 + (num / 1000) + 2;
}

void Count::add3()
{
	num += 3 + (num / 1000) + 3;
}

int Count::Get()
{
	return num;
}