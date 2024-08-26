#pragma once


template<typename T>
class SharedPtr {
private:
	T* ptr_;
	size_t* count_;
	
public:
	//����
		explicit SharedPtr(T* ptr = nullptr):ptr_(ptr),count_(ptr? new size_t(1): nullptr){}

	//��������
		SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), count_(other.count_) {
			if (count_) {
				++(*count);
			}
		}

	//��ֵ������
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


	//��������
		~SharedPtr() {
			release();
	}


	//�����*
		T& operator*() const { return *ptr_; }


	//�����->
		T* operator->() const { return ptr_; }
	//��ȡָ��
		T* get() { return ptr_; }
	//��ȡ����
		T* use_count() const {return count_?*count_: 0}

private:
	//�ͷź���
	void release() {
		if (count_ && --(*count_) == 0) {
			delete ptr_;
			delete count_;
		}
	}

	T* ptr_;
	size_t* count_;
};