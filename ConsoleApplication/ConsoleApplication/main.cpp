#include <iostream>
#include <vector>


void insert_after(std::vector<int>& vector, int first_element, int second_element);

int main()
{
    int n{};
    std::cout << "Input numeber of integers to input: "; std::cin >> n;
    std::vector<int> numbers;

    int input{};
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Input number " << i+1 << ": "; std::cin >> input;
        numbers.push_back(input);
    }

    int first_element{}, second_element{};
    std::cout << "Input first element to search for: "; std::cin >> first_element;
    std::cout << "Input second element to insert: "; std::cin >> second_element;

    insert_after(numbers, first_element, second_element);
}

void insert_after(std::vector<int>& vector, int first_element, int second_element) {
    std::vector<int>::iterator iter{};
    
    for (iter = vector.begin(); iter < vector.end(); iter++)
    {
        if (*iter == first_element) {
            vector.insert(iter + 1, second_element);
            return;
        }
    }
}