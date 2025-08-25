#pragma once

using namespace std;

namespace Test {
	
	template<typename T>
	class vector
	{
	public:
		using iterator = T*;
		using const_iterator = const T*;

		iterator begin()
		{
			return *_start;
		}

		const_iterator begin() const()
		{
			return *_start;
		}
		iterator end()
		{
			return *_finish;
		}

		const_iterator end() const()
		{
			return *_finish;
		}
		

		size_t size() {
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}

		vector() {};

		vector(vector& v)
		{
			_start = v._start;
			_finish = v._finish;
			_end_of_storage = v._end_of_storage;
		}

		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return _start;
		}


		void resize(size_t n, const T& x = T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish != !_end_of_storage)
				{
					push_back(T);
				}
			}
			else
			{

				_finish = _start + n;
			}
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{

				int old = size();

				iterator NewStart = new T[n];

				if (_start)
				{
					while (i = 0; i < old; i++)
					{
						*(NewStart + i) = *(_start + i);
					}
					delete[] _start;
				}
				
				_start = NewStart;
				_finish = _start + old;
				_end_of_storage = _start + n;

			}
			
		}
		// access

		T& operator[] (size_t pos)
		{
			assert(pos >=0 && pos < size())
			return T[pos];
		}

		const T& operator[] (size_t pos)
		{
			assert(pos >= 0 && pos < size())
			return T[pos];
		}
	
		

		// modify

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() > 0 ? 4 : 2 * capacity());
			}
			*(_finish) = x;
			_finish++;
		}

		void pop_back()
		{
			if (size() > 0)
			{
				_finish--;
			}
		}

		void swap(vector<T>& vec)
		{
			swap(vec._start, _start);
			swap(vec._finish, _finish);
			swap(vec._end_of_storage, _end_of_storage);
		}

		

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	}
}