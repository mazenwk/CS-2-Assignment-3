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

	int get_data_count() {
		return m_data_count_;
	}

	void increment._data_count() {
		m_data_count_++;
	}

private:
	T m_data_{};
	int m_data_count_{};
};

template <typename T> class linked_list {
public:
	
	linked_list();
	linked_list(std::vector<T>& vector);
	~linked_list();

	void push(T data);
	void pop();
	T front();

	T operator[] (int index);

	void print_elements();
private:
	node<T>* m_head_{};
	int m_count_{};
};

