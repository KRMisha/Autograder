#include <iostream>
using namespace std;

int main() {
    int A, B;
    cout << "Please enter two integer values: ";
    cin >> A >> B;
    int sum = A + B;
    int sub = A - B;
    int mul = A * B;
    int rem = A % B;
    float div = (float)A / B;
    cout << A << " + " << B << " = " << sum << endl;
    cout << A << " - " << B << " = " << sub << endl;
    cout <<  A << " * " << B << " = " << mul << endl;
    cout <<  A << " / " << B << " = " << div << endl;
    cout <<  A << " % " << B << " = " << rem << endl;
}
