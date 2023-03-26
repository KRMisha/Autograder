#include <iostream>

using namespace std;

int main() {
        int x, y, sum, mult;
        float div;
        cin >> x >> y;
        sum = x+y;
        mult = x*y;
        div = x/y;
        std::cout << x << '\t' << y << endl; 
        std::cout << "x + y = " << sum << endl; 
        std::cout << "x * y = " << mult << endl; 
        std::cout << "x / y = " << div << endl;
}
