#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
T PowerOfTwo(const T& base) {
    return base * base;
}


template <typename T>
std::vector<T> PowerOfTwo(const std::vector<T>& base) {
    std::vector<T> result;
    result.reserve(base.size());
    for (const T& element : base) {
        result.push_back(element * element);
    }
    return result;
}


int main() {
    std::string input;
    std::cout << "введите число(а): ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<int> num_vector;
    int num;

    while (iss >> num) {
        num_vector.push_back(num);
        if (iss.peek() == ',') {
            iss.ignore();
        }
    }

    if (num_vector.size() == 1) {
        int result = PowerOfTwo(num_vector[0]);
        std::cout << result << std::endl;
    } else {
        std::vector<int> result = PowerOfTwo(num_vector);
        for (int value: result) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}