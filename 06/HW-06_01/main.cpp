#include <iostream>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

bool compare_pair(const std::pair<char, int>& a, const std::pair<char, int>& b) {
    if ((a.second > b.second) || (a.second == b.second && a.first < b.first)) {
        return true;
    }
    return false;
}

int main() {
    std::string text;
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    // словарь, для подсчета количества символов
    std::map<char, int> charCount;

    // заполняем словарь
    for (char ch : text) {
        charCount[ch]++;
    }

    // переносим словарь в вектор для сортировки
//    std::vector<std::pair<char, int>> charCountVector;
//    for (const auto& pair : charCount) {
//        charCountVector.push_back(pair);
//    }
    // copy constructor
    std::vector<std::pair<char, int>> charCountVector(charCount.begin(), charCount.end());


    // cортируем вектор
    // для сравнения пар используем отдельную функцию - compare_pair
    std::sort(charCountVector.begin(),
              charCountVector.end(),
              compare_pair);

    for (const auto& pair : charCountVector) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}