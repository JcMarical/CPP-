
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

template<class T> class MyVector {

private:
	T* m_data;
	size_t m_capacity;
	size_t m_size;


public:

	//----------------基础函数-----------------
	//ctor
	MyVector() :m_data(nullptr), m_capacity(0), m_size(0) {};

	//dtor
	~MyVector()
	{
		delete[] m_data;
	}

	//copy constructor 拷贝构造
	MyVector(const MyVector& other) :m_capacity(other.m_capacity), m_size(other.m_size) //为什么可以访问私有变量呢？
	{
		m_data = new T[m_capacity];
		std::copy(other.m_data, other.m_data + m_size, m_data); //移动数据
	}



	//Copy Assignment  拷贝赋值
	MyVector& operator =(const MyVector& other)
	{
		//自检
		if (this != &other)
		{
			delete[] m_data;
			m_capacity = other.m_capacity;
			m_size = other.m_size;
			m_data = new  T[m_capacity];
			std::copy(other.m_data, other.m_data + m_size, m_data); //移动数据

		}
		return *this;
	}
	//------------------增删改查-----------------
	void push_back(const T& value)
	{
		//先判断容量是否够用
		if (m_size == m_capacity)
		{
			//先申请空间
			reserve(m_capacity == 0 ? 1 : m_capacity << 1);
		}

		//插入数据
		m_data[m_size++] = value;
	}


	int size()
	{
		return m_size;
	}
	int capacity()
	{
		return m_capacity;
	}

	//public MyVector<T> operator[](const int& index)
	//注意，这是数组取值，返回的是一个值
	T& operator[](size_t index)
	{
		//先判断index是否越界
		if (index >= m_size)
		{
			throw std::out_of_range("index out of range");
		}

		return m_data[index];
	}


	//const 版本的访问
	const T& operator[](size_t index) const
	{
		if (index >= m_size)
		{
			throw std::out_of_range("index out of range");
		}
		return m_data[index];
	}




	T insert(size_t index, T value)
	{
		//先判断index是否越界
		if (index > m_size)
		{
			throw std::out_of_range("index out of range");
		}

		if (index == m_size)
		{
			reserve(m_capacity == 0 ? 1 : m_capacity << 1);

		}

		//移动数据
		for (size_t i = m_size; i > index; i--)
		{
			m_data[i] = m_data[i - 1];

		}

		m_data[index] = value;
		++m_size;
	}
	void pop_back()
	{
		if (m_size > 0)
		{
			--m_size;
		}
	}

	void clear()
	{
		m_size = 0;
	}

	///迭代器指针
	T* begin()
	{
		return m_data;
	}

	T* end()
	{
		return m_data + m_size;
	}

	const T* begin() const
	{
		return m_data;
	}

	const T* end() const
	{
		return m_data + m_size;
	}

	void printElements() const
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	//扩容函数

	void  reserve(size_t new_capacity)
	{
		//判断是否需要扩容
		if (new_capacity > m_capacity)
		{
			T* new_data = new T[new_capacity];
			std::copy(m_data, m_data + m_size, new_data);
			delete[] m_data;
			m_data = new_data;
			m_capacity = new_capacity;
		}
	}


	void shrink_to_fit()
	{

	}
};

int main()
{
	MyVector<int> myVector;

	int N;
	std::cin >> N;
	getchar();



	std::string line;
	for (int i = 0; i < N; i++)
	{
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string command;
		iss >> command;

		//push
		if (command == "push")
		{
			int value;
			iss >> value;
			myVector.push_back(value);
		}

		if (command == "size")
		{
			std::cout << myVector.size() << std::endl;
		}

		if (command == "get")
		{
			int value;
			iss >> value;


			std::cout << myVector[value] << std::endl;
		}

		if (command == "insert")
		{
			int a, b;
			iss >> a;
			iss >> b;

			myVector.insert(a, b);
		}

		if (command == "pop")
		{
			myVector.pop_back();
		}

		if (command == "clear")
		{
			myVector.clear();
		}

		if (command == "print")
		{
			if (myVector.size() == 0)
			{
				std::cout << "empty" << std::endl;
			}
			myVector.printElements();
		}

		if (command == "iterator")
		{
			if (myVector.size() == 0)
			{
				std::cout << "empty" << std::endl;
			}
			myVector.printElements();
		}

		if (command == "foreach")
		{
			if (myVector.size() == 0)
			{
				std::cout << "empty" << std::endl;
			}
			myVector.printElements();
		}

	}
}




