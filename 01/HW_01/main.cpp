#include <iostream>
#include <vector>
#include <algorithm>

//Напишите программу, которая все нечётные элементы массива (std::vector) умножает на 3 с помощью лямбда-функции.
//Циклы использовать не нужно.

int main() {
    std::vector<int> v_1 = {4, 7, 9, 14, 12};
    std::cout << "Входные данные:  ";
    for (int num : v_1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int multiplier = 3;
    // Use a lambda function and std::for_each to iterate through the vector and multiply elements at even positions by the constant.
    std::for_each(v_1.begin(), v_1.end(), [multiplier](int &num) {
        if (num % 2 != 0) {num *= multiplier;}
    });

    std::cout << "Выходные данные:  ";
    for (int num : v_1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
