#pragma once
#include <iostream>
#include <mutex>
using namespace std;

class A
{

};

class B
{

};

template<typename T>
class Singleton2
{
public:
	static T* GetInstance()
	{
		static T instance;
		return &instance;
	}
private:
	Singleton2() {};
};

template <typename T>
class Singleton
{
public:
    static T* GetInstance()
    {
        if (pSingle == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (pSingle == nullptr)
            {
                pSingle = new T();

            }

        }
        return pSingle;

    }
private:
    Singleton() {}
    static T* pSingle;
    static mutex mtx;
};