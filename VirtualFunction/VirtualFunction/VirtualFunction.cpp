#include <iostream>


class A
{
	int a;
};


class B :public A
{
	int b;
};

void main()
{
	int test1;
	int test2;

	A* a = new A();
	B* b = new B();
	A* c = new B();
}