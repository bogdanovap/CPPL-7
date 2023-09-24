#include <iostream>
#include <sstream>

class CMySuperFunctor {
private:
    int sum_;
    int count_;
public:
    CMySuperFunctor() : sum_(0), count_(0) {}

    void operator()(int number) {
        if (number % 3 == 0) {
            sum_ += number;
            count_++;
        }
    }

    int get_sum() const {
        return sum_;
    }

    int get_count() const {
        return count_;
    }

};

int main() {
    CMySuperFunctor functor;
    std::string input;
    int num;

    std::cout << "Введите числа: ";
    std::getline(std::cin, input);
    std::istringstream iss(input);

    while (iss >> num) {
        functor(num);
    }

    std::cout << "get_sum() = " << functor.get_sum() << std::endl;
    std::cout << "get_count() = " << functor.get_count() << std::endl;

    return 0;
}
