#include <iostream>

using namespace std;

int main() {
        int i1,i2,i3;
        i1=2;
        i2=5;
        i3=-3;
        double d1,d2,d3;
        d1= 2.0;
        d2= 5.0;
        d3= -0.5;

        std::cout <<i1 + (i2 * i3)<<endl;
        std::cout <<i1 * (i2 + i3)<<endl;
        std::cout <<i1 / (i2 + i3)<<endl;
        std::cout <<i1 / i2 + i3<<endl;
        std::cout <<3 + 4 + 5 / 3<<endl;
        std::cout <<(3 + 4 + 5) / 3<<endl;
        std::cout << d1 + (d2 * d3) <<endl;
        std::cout << d1 + d2 * d3 <<endl;
        std::cout << d1/d2-d3 <<endl;
        std::cout << d1/(d2-d3) <<endl;
        std::cout << d1 + d2 + d3 / 3 <<endl;
        std::cout << (d1 + d2 + d3) / 3 <<endl;   
}       
        