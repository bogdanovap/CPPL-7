#include <iostream>

class smart_array {
private:
    int current_pos;
    int *arr;
public:
    int size;
    smart_array(int size);
    ~smart_array();
    void add_element(int element);
    int get_element(int index);
    smart_array& operator=(smart_array &arr2);
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

smart_array& smart_array::operator=(smart_array &rhs){
    delete[] arr;
    size = rhs.size;
    arr = new int[size];
    current_pos = 0;
    for (int i = 0; i < size; i++){
        int element = rhs.get_element(i);
        add_element(element);
    }
    return *this;
}


int main() {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;

    std::cout << arr.get_element(0) << std::endl;

    return 0;
}


