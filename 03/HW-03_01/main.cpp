#include <iostream>

class smart_array {
private:
    int size;
    int current_pos;
    int *arr;
public:
    smart_array(int size);
    ~smart_array();
    void add_element(int element);
    int get_element(int index);
};

smart_array::smart_array(int size) {
    this->size = size;
    this->arr = new int[size];
    this->current_pos = 0;
}

smart_array::~smart_array() {
    delete[] arr;
}

void smart_array::add_element(int element) {
    if (current_pos >= size){
        throw std::out_of_range("array is full");
    }
    arr[current_pos] = element;
    current_pos++;
}

int smart_array::get_element(int index){
    if (index >= size or index < 0){
        throw std::out_of_range("index is out of range");
    }
    return arr[index];
}

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}


