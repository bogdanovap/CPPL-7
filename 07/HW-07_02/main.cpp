#include <iostream>
#include <set>
#include <vector>
#include <list>

template <typename TContainer>
void print_container(const TContainer& container) {
    auto element = container.begin();
    while (true) {
        std::cout << *element;
        ++element;
        if (element == container.end()) break;
        std::cout << ", ";
    }
//    for (const auto& item : container) {
//        std::cout << item;
//        if (item != *container.end()) {
//            std::cout << ", ";
//        }
//    }
    std::cout << std::endl;
}

int main() {
    std::cout << "test_set: ";
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::cout << "test_list: ";
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::cout << "test_vector: ";
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);

    return 0;
}
