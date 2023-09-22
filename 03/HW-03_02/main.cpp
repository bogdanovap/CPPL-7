#include <iostream>

class smart_array {
private:
    int size;
    int current_pos;
    int *arr;
    void copy_array(const smart_array &rhs);
public:
    smart_array(int size);
    ~smart_array();
    void add_element(int element);
    int get_element(int index) const;
    smart_array(const smart_array &rhs);
    smart_array& operator=(const smart_array &rhs);
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

int smart_array::get_element(int index) const {
    if (index >= size or index < 0){
        throw std::out_of_range("index is out of range");
    }
    return arr[index];
}

// функция copy_array() копирует элементы массива
// (создана для того, чтобы избежать дублирования кода)
void smart_array::copy_array(const smart_array &rhs) {
    size = rhs.size;
    arr = new int[size];
    current_pos = 0;
    for (int i = 0; i < size; i++) {
        int element = rhs.get_element(i);
        add_element(element);
    }
}

// Кроме операторе присваивания, вам нужно реализовать конструктор копирования тоже
smart_array::smart_array(const smart_array &rhs) {
    copy_array(rhs);
}

smart_array& smart_array::operator=(const smart_array &rhs){
    // В операторе присваивания вам нужно предусмотреть ситуацию,
    // когда пользователь класса пытается присвоить класс самому себе: arr = arr;.
    // Обычно делают проверку сравнением указателя. И если указатели равны,
    // то просто код оператора присваивания ничего не делает и возвращает ссылку на себя
    if (this == &rhs){
        return *this;
    }
    delete[] arr;
    copy_array(rhs);
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

    // присваивание
    arr = new_array;
    std::cout << arr.get_element(0) << std::endl;

    // копирование
    smart_array arr3 = new_array;
    std::cout << arr3.get_element(1) << std::endl;

    return 0;
}


