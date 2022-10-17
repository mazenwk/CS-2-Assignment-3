#include "linked_list.h"

#pragma region Node

template <typename T>
node<T>::node(T data, const int data_count = 1) : m_next(nullptr) {
    m_data_ = data;
    m_data_count_ = data_count;
}

template <typename T>
node<T>::~node() {
    if (m_next != nullptr) {
        delete m_next;
        m_next = nullptr;
    }
}

template <typename T>
T node<T>::get_data() {
    return m_data_;
}

template <typename T>
int node<T>::get_data_count() {
    return m_data_count_;
}

template <typename T>
void node<T>::increment_data_count() {
    m_data_count_++;
}

#pragma endregion


#pragma region Linked List

template <typename T> 
linked_list<T>::linked_list() : m_head_(nullptr) {}

template <typename T>
linked_list<T>::linked_list(std::vector<T>& vector) : m_head_(nullptr) {
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

template <typename T> 
linked_list<T>::~linked_list() {
    if (m_head_ != nullptr) {
        if (m_head_->m_next != nullptr) {
            delete m_head_->m_next;
            m_head_->m_next = nullptr;
        }

        delete m_head_;
        m_head_ = nullptr;
    }
}

template <typename T> 
void linked_list<T>::push(T data) {
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

template <typename T> 
void linked_list<T>::pop() {
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

template <typename T> 
T linked_list<T>::front() {
		return m_head_->getData();
}

template <typename T> 
T linked_list<T>::operator[] (int index) {
    int current_index = 0;
    node<T>* itr = m_head_;
    while (itr != nullptr) {
        if (current_index == index) {
            return itr->getData();
        }
        current_index++;
        itr = itr->next;
    }
}

template <typename T> 
void linked_list<T>::print_elements() {
		if (m_count_ > 0) {
			node<T>* itr = m_head_;
			int index{};

			while (itr->m_next != nullptr) {
				std::cout << "Element number [" << index + 1 << "] is: " << itr->get_data() << " and was repeated " << itr->get_data_count() << " times" << '\n';
				itr = itr->m_next;
				index++;
			}

			std::cout << std::endl;
		}
	}


#pragma endregion