#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "linked_list.h"
#include <iostream>
#include <vector>


void insert_after(std::vector<int>& vector, int first_element, int second_element);
void print_vector(const std::vector<int>& vector);

void t() {
    int input_count{};
    std::cout << "Input number of integers to input: "; std::cin >> input_count;
    std::vector<int> numbers_vector;

    int input{};
    for (int i = 0; i < input_count; i++)
    {
        std::cout << "Input number " << i + 1 << ": "; std::cin >> input;
        numbers_vector.push_back(input);
    }

    int first_element{}, second_element{};
    std::cout << "Input first element to search for: "; std::cin >> first_element;
    std::cout << "Input second element to insert: "; std::cin >> second_element;

    insert_after(numbers_vector, first_element, second_element);
    print_vector(numbers_vector);

    linked_list<int> numbers_list(numbers_vector);
    numbers_list.print_elements();
    std::cout << "The sum of the list is: " << numbers_list.get_elements_sum() << '\n';
}

int main()
{

    t();
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

