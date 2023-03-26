#include <iostream>

using namespace std;

int main() {
        int A, B, w, x, y, z;
        float p;
        cin >> A >> B;
        w = A+B;
        x = A-B;
        y = A*B;
        z = A/B;
        p = A%B;
        std::cout <<"Please enter two integer values" << A << B << endl; 
        std::cout <<A<<'+'<< B << '=' << w << endl;
        std::cout <<A<<'-'<< B << '=' << x << endl;
        std::cout <<A<<'*'<< B << '=' << y << endl;
        std::cout <<A<<'/'<< B << '=' << z << endl;
        std::cout <<A<<'%'<< B << '=' << p << endl;
}
