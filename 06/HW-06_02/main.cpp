#include <iostream>
#include <set>

int main() {
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    // используем - std::set
    // greater - упорядочить в порядке убывания
    std::set<int, std::greater<int>> setOfNumbers;

    std::cout << "Введите числа:\n";
    int num;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        setOfNumbers.insert(num);
    }

    // Выводим уникальные числа в порядке убывания
    for (int number : setOfNumbers) {
        std::cout << number << std::endl;
    }

    return 0;
}
