#pragma once
#include <vector>

template <typename T> struct node {
public:
	node<T>* m_next{};

	explicit node(T data, int data_count = 1);
	~node();

	T get_data();
	int get_data_count() const;

	void increment_data_count();

private:
	T m_data_{};
	int m_data_count_{};
};

template <typename T> class linked_list {
public:
	
	linked_list();
	explicit linked_list(std::vector<T>& vector);
	~linked_list();

	void push(T data);
	void pop();
	T front();

	T operator[](int index);

	void print_elements();
private:
	node<T>* m_head_{};
	int m_count_{};
};