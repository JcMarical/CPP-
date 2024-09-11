
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

	//----------------��������-----------------
	//ctor
	MyVector() :m_data(nullptr), m_capacity(0), m_size(0) {};

	//dtor
	~MyVector()
	{
		delete[] m_data;
	}

	//copy constructor ��������
	MyVector(const MyVector& other) :m_capacity(other.m_capacity), m_size(other.m_size) //Ϊʲô���Է���˽�б����أ�
	{
		m_data = new T[m_capacity];
		std::copy(other.m_data, other.m_data + m_size, m_data); //�ƶ�����
	}



	//Copy Assignment  ������ֵ
	MyVector& operator =(const MyVector& other)
	{
		//�Լ�
		if (this != &other)
		{
			delete[] m_data;
			m_capacity = other.m_capacity;
			m_size = other.m_size;
			m_data = new  T[m_capacity];
			std::copy(other.m_data, other.m_data + m_size, m_data); //�ƶ�����

		}
		return *this;
	}
	//------------------��ɾ�Ĳ�-----------------
	void push_back(const T& value)
	{
		//���ж������Ƿ���
		if (m_size == m_capacity)
		{
			//������ռ�
			reserve(m_capacity == 0 ? 1 : m_capacity << 1);
		}

		//��������
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
	//ע�⣬��������ȡֵ�����ص���һ��ֵ
	T& operator[](size_t index)
	{
		//���ж�index�Ƿ�Խ��
		if (index >= m_size)
		{
			throw std::out_of_range("index out of range");
		}

		return m_data[index];
	}


	//const �汾�ķ���
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
		//���ж�index�Ƿ�Խ��
		if (index > m_size)
		{
			throw std::out_of_range("index out of range");
		}

		if (index == m_size)
		{
			reserve(m_capacity == 0 ? 1 : m_capacity << 1);

		}

		//�ƶ�����
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

	///������ָ��
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
	//���ݺ���

	void  reserve(size_t new_capacity)
	{
		//�ж��Ƿ���Ҫ����
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




