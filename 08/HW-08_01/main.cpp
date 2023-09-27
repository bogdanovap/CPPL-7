#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;

    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};

    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    // нам нужно чтобы каждый оюъект указывал на уникальную память
    // поэтому нам нужен unique pointer
    // создаем новый объект класса через make_unique и возвращем unique pointer
    std::unique_ptr<tridiagonal_matrix> clone() {
        return std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
    }
};

int main() {
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    // на объект матрицы будет указывать умный указатель
    // это значит что память освободится при выходе из области видимости
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    return 0;
}
