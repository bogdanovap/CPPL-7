#include <vector>
#include <iostream>

template <typename T>
class CTable {
private:
    int rows_;
    int cols_;
    std::vector<std::vector<T>> data_;
public:
    CTable(int rows, int cols) : rows_(rows), cols_(cols) {
        data_.resize(rows, std::vector<T>(cols));
    }

    // оператор [], константный
    std::vector<T>& operator[](int index) const {
        return data_[index];
    }

    // оператор []
    std::vector<T>& operator[](int index) {
        return data_[index];
    }

    // размер таблицы
    int Size() const {
        return rows_ * cols_;
    }
};

int main() {
    auto test = CTable<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; // выводит 4

    std::cout << test.Size() << std::endl; // выводит 6

    return 0;
}
