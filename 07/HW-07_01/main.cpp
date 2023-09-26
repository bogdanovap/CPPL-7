#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

template <typename T>
void remove_duplicates(std::vector<T>& vec) {
//    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
//    std::cout << "NOT sorted" << std::endl;
//    for (const int& value : vec) {
//        std::cout << value << " ";
//    }

//  std::unique - итератор на конец массива уникальных элементотв
//  удаляет элементы идущие подряд. поэтому нужно отсортировать массив
//  vec.erase - удаляеб элементы, начиная с итератора, который вернул std::unique
    std::sort(vec.begin(), vec.end());
//    for (const int& value : vec) {
//        std::cout << value << " ";
//    }
    auto unique_iterator = std::unique(vec.begin(), vec.end());
    vec.erase(unique_iterator, vec.end());
}

int main() {
    std::string input;
    int num;

    std::cout << "IN : ";
    std::getline(std::cin, input);

    std::istringstream iss(input);

    std::vector<int> numbers;
    while (iss >> num) {
        numbers.push_back(num);
    }

    remove_duplicates(numbers);

    std::cout << "OUT: ";
    for (const int& value : numbers) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
