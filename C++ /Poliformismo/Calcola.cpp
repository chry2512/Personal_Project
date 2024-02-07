#include <iostream>

class Counter {
public:
    Counter() : value(0) {};
    Counter(int n) : value(n) {};
    int getValue() {
        return value;
    }
    void increment() { value++; }

private:
    int value;
};

class BigCounter : public Counter {
public:
    BigCounter(int n) : Counter(n) {}
    void increment() {
        Counter::increment();
        Counter::increment();
    }
};

int main() {
    Counter c1(5);
    BigCounter c2(5);

    std::cout << c1.getValue() << std::endl;
    std::cout << c2.getValue() << std::endl;
    c1.increment();
    c2.increment();
    std::cout << c1.getValue() << std::endl;
    std::cout << c2.getValue() << std::endl;

    return 0;
}
