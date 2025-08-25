#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class A {
public:
	virtual void f() { cout << "A::f()" << endl; }
	virtual ~A() { f(); };
};

class B : public A 
{
	 void f() { cout << "B::f()" << endl; }
	 ~B() { f(); }
};

int main() {
	int i = 0;
	cout << ++(++i);

	i = 0;
	cout << (i++)++;
}