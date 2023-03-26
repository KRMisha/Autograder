#include <iostream>
using namespace std;

int main() {

    int A, B, sum, subs, mult, modul;
    float div;
    cin >> A >> B;
    sum = A + B;
    subs = A - B;
    mult = A * B;
    div = float(A) / float(B);
    modul = A % B;
    cout << A << '\t' << B << endl;
    cout << "A + B = " << sum << endl;
    cout << "A - B = " << subs << endl;
    cout << "A * B = " << mult << endl;
    cout << "A / B = " << div << endl;
    cout << "A % B = " << modul << endl;

}