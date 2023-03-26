#include <iostream>

using namespace std;

int main() {
        std::cout << "(7 == 5):" << float(7 == 5)<< endl;
        std::cout << "(7 >= 5):" << float(7 >= 5) << endl;
        std::cout << "(7 != 5):" << float(7 != 5) << endl;
        std::cout << "(7 <= 5):" << float(7 <= 5) << endl;
        std::cout << "(7 >= 5 ? 100 : -100): " << float(7 >= 5 ? 100 : -100) << endl;
}       