#pragma once
#include <iostream>
#include <algorithm>
#include <assert.h>
//迭代器定义->内存指针定义->迭代器函数->内存获取-> reserve->出入、交换、(插入删除)->重排->
// ->构造(普通、参数、迭代器)拷贝析构->获取（改查）->插入删除



namespace CryDust
{
	template<class T>
	class vector
	{
	public:
		//----------------Iterator：pointer-----------------
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin() { return _start; } //返回起始迭代器
		iterator end() { return _finish; } //返回结束迭代器
		const_iterator begin() const { return _start; } //返回起始迭代器
		const_iterator end() const { return _finish; } //返回结束迭代器

		//------------------基础函数-----------------
		vector() {};

		vector(int n, const T& value = T())
		{
			resize(n, value); //初始化时调用resize函数
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}	

		vector(const vector<T>& v)
		{
			for (int i = 0; i < v.size(); i++)
			{
				push_back(v[i]);
			}
		}

		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endOfStorage = nullptr;
		}

		size_t size() const
		{
			return _finish - _start; //返回当前元素个数
		}

		size_t capacity() const
		{
			return _end_of_storage - _start; //返回当前容量
		}

		reserve(size_t n)
		{
			if (n > capacity())
			{
				int old = size();
				T* newStart = new T[n]; //申请新的内存空间
				if (_start)
				{
					for (int i = 0; i < old; ++i) //将原有数据拷贝到新空间
					{
						newStart[i] = _start[i];
					}
					delete[] _start; //释放原有内存
				}
				_start = newStart; //更新起始指针
				_finish = _start + old; //更新尾指针
				_end_of_storage = _start + n; //更新存储结束指针
			}
		}


		resize(size_t n, const T& value = T())
		{
			if (n > size)
			{
				reserve(n); //确保容量足够
				while (finish != _end_of_storage)
				{
					push_back(value);
				}
			}
			else
			{
				_finish = _start + n; //如果新大小小于当前大小，直接更新尾指针
			}
		}
	//------------------access--------------------
		T& operator[](size_t pos)
		{
			assert(pos < size()); //确保索引合法
			return *(_start + pos); //返回指定索引的元素
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size()); //确保索引合法
			return *(_start + pos); //返回指定索引的元素
		}

	//----------------------modify----------------------
	void push_back(const T& x)
	{
		if (_finish == _end_of_storage) //如果尾指针等于存储结束指针，说明需要扩容
		{
		
			reserve(capacity() == 0 ? 4 : 2 * capacity()); //调用reserve函数扩容
		}

		*_finish = x;
		_finish++;
	}

	void pop_back(const T& x)
	{
		assert(size() > 0); //确保当前有元素可以删除
		_finish--;
	}

	void swap(vector<T>& v)
	{
		std::swap(_start, v._start); //交换起始指针
		std::swap(_finish, v._finish); //交换尾指针
		std::swap(_end_of_storage, v._end_of_storage); //交换存储结束指针
	}

	iterator insert(iterator pos, const T& x)
	{
		assert(pos >= _start && pos <= _finish); //确保插入位置合法
		if (_finish == _end_of_storage) //如果尾指针等于存储结束指针，说明需要扩容
		{
			int n = pos - start;
			reserve(capacity() ? 2 * capacity(): 4); //调用reserve函数扩容
			pos = _start + n; 
		}
		iterator end = _finish - 1; //记录原尾指针位置
		while (end >= pos) //从尾部开始向前移动元素
		{
			*(end + 1) = *end; //将元素向后移动一位
			end--;
		}
		*pos = x; //在指定位置插入新元素
		return pos;

	}

	iterator erase(iterator pos)
	{
		assert(pos >= _start && pos < _finish); //确保删除位置合法
		iterator it = pos + 1; //获取下一个元素的迭代器
		while (it < _finish) //从删除位置开始向后移动元素
		{
			*(it - 1) = *it; //将后面的元素向前移动一位
			it++;
		}
		_finish--; //更新尾指针
		return pos; //返回新的尾指针位置
	}



	private:
		iterator _start = nullptr; //数据起始指针
		iterator _finish = nullptr; //数据尾指针
		iterator _end_of_storage = nullptr; //数据存储结束指针

	};
}