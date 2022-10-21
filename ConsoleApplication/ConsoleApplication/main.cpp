#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "linked_list.h"
#include <iostream>
#include <vector>


void insert_after(std::vector<int>& vector, int first_element, int second_element);
void print_vector(const std::vector<int>& vector);

void test_vector() {
    int n{};
    std::cout << "Input number of integers to input: "; std::cin >> n;
    std::vector<int> numbers;

    int input{};
    for (int i = 0; i < n; i++)
    {
        std::cout << "Input number " << i + 1 << ": "; std::cin >> input;
        numbers.push_back(input);
    }

    int first_element{}, second_element{};
    std::cout << "Input first element to search for: "; std::cin >> first_element;
    std::cout << "Input second element to insert: "; std::cin >> second_element;

    insert_after(numbers, first_element, second_element);
    print_vector(numbers);
}

void test_linked_list() {
    linked_list<int> numbers;
    numbers.print_elements();
    numbers.push(1);
    numbers.print_elements();

    numbers.push(3);
    numbers.push(87);
    numbers.print_elements();

    numbers.pop();
    numbers.print_elements();

}

void test_linked_list_2() {
    int n{};
    std::cout << "Input number of integers to input: "; std::cin >> n;
    std::vector<int> vector;

    int input{};
    for (int i = 0; i < n; i++)
    {
        std::cout << "Input number " << i + 1 << ": "; std::cin >> input;
        vector.push_back(input);
    }

    int first_element{}, second_element{};
    std::cout << "Input first element to search for: "; std::cin >> first_element;
    std::cout << "Input second element to insert: "; std::cin >> second_element;

    insert_after(vector, first_element, second_element);
    print_vector(vector);

    linked_list<int> numbers(vector);
    numbers.print_elements();
}

int main()
{
    //test_vector();
    //test_linked_list();
    test_linked_list_2();

    _CrtDumpMemoryLeaks();
    return 0;
}

void insert_after(std::vector<int>& vector, const int first_element, const int second_element) {

	for (auto itr = vector.begin(); itr < vector.end(); ++itr)
    {
        if (*itr == first_element) {
            vector.insert(itr + 1, second_element);
            break;
        }
    }
}

void print_vector(const std::vector<int>& vector) {
	for (std::size_t i = 0; i < vector.size(); ++i) {
        std::cout << "Element number [" << i + 1 << "] is: " << vector[i] << '\n';
	}
}

