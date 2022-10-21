#pragma once
#include <iostream>
#include <vector>

template <typename T> struct node {
public:
	node<T>* m_next{};

	explicit node(T data, const int data_count = 1) : m_next(nullptr) {
		m_data_ = data;
		m_data_count_ = data_count;
	}

	~node() {
		if (m_next != nullptr) {
			delete m_next;
			m_next = nullptr;
		}
	}

	T get_data() {
		return m_data_;
	}

	int get_data_count() const {
		return m_data_count_;
	}

	void increment_data_count() {
		m_data_count_++;
	}

private:
	T m_data_{};
	int m_data_count_{};
};

template <typename T> class linked_list {
public:
	linked_list() : m_head_(nullptr) {
		
	}

	explicit linked_list(std::vector<T>& vector) : m_head_(nullptr) {
		for (std::size_t i = 0; i < vector.size(); ++i) {
			node<T>* itr = m_head_;
			node<T>* duplicate_element{};
			bool do_exist_already{ false };

			if (m_head_ == nullptr) {
				push(vector[i]);
				continue;
			}

			while (itr != nullptr && !do_exist_already) {
				if (itr->get_data() == vector[i]) {
					duplicate_element = itr;
					do_exist_already = true;
				}
				itr = itr->m_next;
			}

			if (do_exist_already) {
				duplicate_element->increment_data_count();
			}
			else {
				push(vector[i]);
			}
		}
	}

	void push(T data) {
		if (m_head_ == nullptr) {
			m_head_ = new node<T>(data);
		} else {
			node<T>* itr = m_head_;

			while (itr->m_next != nullptr) {
				itr = itr->m_next;
			}
			itr->m_next = new node<T>(data);
		}

		m_count_++;
	}

	void pop() {
		if (m_head_->m_next == nullptr) {
			delete m_head_;
			m_head_ = nullptr;
		}
		else {
			node<T>* itr = m_head_;

			while (itr->m_next != nullptr) {
				if (itr->m_next->m_next == nullptr) {
					delete itr->m_next;
					itr->m_next = nullptr;
				} else {
					itr = itr->m_next;
				}
			}
		}

		m_count_--;
	}

	void print_elements() {
		if (m_count_ > 0) {
			node<T>* itr = m_head_;
			int index{};

			while (itr != nullptr) {
				std::cout << "Element number [" << index + 1 << "] is: " << itr->get_data() << " and was repeated " << itr->get_data_count() << " times" << '\n';
				itr = itr->m_next;
				index++;
			}

			std::cout << std::endl;
		}
	}

	T get_elements_sum() {
		T sum{};

		if (m_count_ > 0) {
			node<T>* itr = m_head_;
			int index{};

			while (itr != nullptr) {
				sum += itr->get_data() * itr->get_data_count();
				itr = itr->m_next;
				index++;
			}

			std::cout << std::endl;
		}

		return sum;
	}

	~linked_list() {
		if (m_head_ != nullptr) {
			if (m_head_->m_next != nullptr) {
				delete m_head_->m_next;
				m_head_->m_next = nullptr;
			}

			delete m_head_;
			m_head_ = nullptr;
		}
	}

private:
	node<T>* m_head_{};
	int m_count_{};
};

