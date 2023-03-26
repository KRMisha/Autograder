#include<iostream>
using namespace std;
int main() {
    int A, B, hand;
    cout << "Please enter two integer values: \n";
    cin >> A >> B;
    hand = A;
    A = B;
    B = hand;
    cout << "value of A is : " << A << endl;
    cout << "value of B is : " << B << endl;
    }