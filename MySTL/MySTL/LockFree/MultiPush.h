#pragma once


#include <atomic>
#include <memory>

namespace LockFree {
	template <typename T>
	class MulPopPush {
	private:
		struct node {
			std::shared_ptr<T> data; // Use shared_ptr for automatic memory 
			node* next;
			node(const T& val) : next(nullptr) {}
		};
		std::atomic<Node*> head;
		std::atomic<Node*> tail;
		node* pop_head{

			node* const old_head = head.load();

		//<-- -1
			if (old_head == tail.load())
			{
				return nullptr; // Empty list
			}
			head.store(old_head->next);
			return old_head;
		}
	public:
		SinglePopPush() : head(new node), tail(head.load) {}
		SinglePopPush(const SinglePopPush& other) = delete;
		SinglePopPush& operator=(const SinglePopPush& other) = delete;
		~SinglePopPush() {
			while (node* const old_head = head.load()) {
				head.store(old_head->next);
				delete old_head;
			}
		}

		std::shared_ptr<T> pop() {
			node* old_head = pop_head();
			if (!old_head)
			{
				return std::shared_ptr<T>(); // Return nullptr if the list is empty
			}
			// <-- -2
			std::shared_ptr<T> res(old_head->data);
			delete old_head;
			return res;
		}

		void push(const T& new_value) {
			std::unique_ptr<T> new_data = std::make_unique<T>(new_value);

			counted_node_ptr new_next;
			new_next.ptr = new node;//实际数据存储
			new_next.external_count = 1;

			for(;;)

		}

		bool empty() const {
			return head.load() == nullptr;
		}

		for (;;)
		{
			//<-- -1
			node* const old_tail = tail.load();
			T* old_data = nullptr;
			
			//<-- -2
			if (old_tail->data.compare_exchange_strong(old_data,new_data.get())
			{

				old_tail->next = new_next;
				//<-- -3
				tail.store(new_next.ptr);
				new_data.release(); // Transfer ownership to the list
				return;
			}
		}

	};
}