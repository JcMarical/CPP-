#pragma once

//sharedptr

//内存
//计数

//operator->
//operator*

//release

//显式无参构造
//拷贝构造
//赋值操作符
//析构函数

//get()
//use_count(）

namespace CryDust {

	template<typename T>
	class SharedPtr {
	private:
		T* ptr_;
		size_t* count_;

	private:
		//释放函数
		void release() {
			if (count_ && --(*count_) == 0) {
				delete ptr_;
				delete count_;
			}
		}

	public:
		//运算符*
		T& operator*() const { return *ptr_; }
		//运算符->
		T* operator->() const { return ptr_; }


		//构造
		explicit SharedPtr(T* ptr = nullptr) :ptr_(ptr), count_(ptr ? new size_t(1) : nullptr) {}

		//拷贝构造
		SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), count_(other.count_) {
			if (count_) {
				++(*count);
			}
		}

		//赋值操作符
		SharedPtr& operator=(const SharedPtr& other) {
			if (this != &other) {
				release();
				ptr_ = other.ptr_;
				count_ = other.count_;
				if (count_)
				{
					*count_++;
				}
			}
			return this;
		}


		//析构函数
		~SharedPtr() {
			release();
		}




		//获取内存
		T* get() { return ptr_; }
		//获取计数
		size_t* use_count() const { return count_ ? *count_ : 0 }
	};
}


