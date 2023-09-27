#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    // предполагаем что несколько узлов могут указывать на одного родителя
    // этот родитель удаляется тогда, когда больше не будет объектов, которые на него указывают
    // чтобы избежать циклической зависимости, нужно чтобы счетчик ссылок не увеличивался
    // поэтому используем weak pointer
    std::weak_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called " << m_value << "\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);

        node1->parent = node2;
        node2->parent = node1;
    }

    return 0;
}
