#include <iostream>
#include <vector>
#include <print>

class MyContainer {


private:
    std::vector<int> data;

public:
    MyContainer(const std::initializer_list<int>& values) : data(values) {}

    // Nested Iterator class
    class Iterator {
    private:
        std::vector<int>::iterator iter;

    public:
        // Constructor
        Iterator(std::vector<int>::iterator it) : iter(it) {}

        // Dereference operator
        int& operator*() { return *iter; }

        // Pre-increment operator
        Iterator& operator++() {
            ++iter;
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality comparison
        bool operator==(const Iterator& other) const {
            return iter == other.iter;
        }

        // Inequality comparison
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

public:
    using value_type = int;
    using iterator = MyContainer::Iterator;


    // Begin iterator
    Iterator begin() { return Iterator(data.begin()); }

    // End iterator
    Iterator end() { return Iterator(data.end()); }
};

int main() {
    MyContainer container = { 1, 2, 3, 4, 5 };

    for (MyContainer::Iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }

    for ( auto elem   : container) {
        std::println("{}", elem);
    }

    std::cout << std::endl;

    return 0;
}