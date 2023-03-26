#include <iostream>

using namespace std;
//sizeof() 함수는 메모리 공간을 차지하는 byte수를 return 합니다.
int main() {       
        unsigned short siX; // (int) 생략 가능 unsigned iX;
        long liX;
        long long lliX;
        std::cout << "sizeof(siX):" << sizeof(short) << endl; 
        std::cout << "sizeof(iX):" << sizeof(int)<< endl; 
        std::cout << "sizeof(liX):" << sizeof(float) << endl; 
        std::cout << "sizeof(lliX):" << sizeof(double) << endl;
}
