#include <iostream>
#include <variant>
#include <vector>
#include <string>
#include <ctime>

std::variant<int, std::vector<int>, std::string> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::vector<int>, std::string> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main() {
    auto variantResult = get_variant();

    if (std::holds_alternative<int>(variantResult)) {
        auto res = std::get<int>(variantResult);
        std::cout << "число * 2: " << res * 2 << std::endl;
    }
    else if (std::holds_alternative<std::string>(variantResult)) {
        auto res = std::get<std::string>(variantResult);
        std::cout << "строка: " << res << std::endl;
    }
    else if (std::holds_alternative<std::vector<int>>(variantResult)) {
        auto res = std::get<std::vector<int>>(variantResult);
        std::cout << "вектор: ";
        for (auto& i : res) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
