#include <iostream>

using namespace std;

int main() {
    int A, B;
    cout << "Please enter two integer values: ";
    cin >> A;
    cin >> B;
    float quotient;
    quotient = float(A)/float(B);
    cout << "A + B = " << A+B << endl;
    cout << "A - B = " << A-B << endl;
    cout << "A * B = " << A*B << endl;
    cout << "A / B = " << quotient << endl;
    cout << "A % B = " << A%B << endl;
}