
#include <iostream>

    int* createpointer() {
        int *p = new int(42);
        return p;
    }

    int main()
    {
        int* ptr = _createpointer();
        std::cout << *ptr << std::endl;
        delete ptr;
        return 0;
}


