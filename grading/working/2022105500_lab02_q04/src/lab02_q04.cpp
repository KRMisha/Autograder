//
//  main.cpp
//  sol_extend_4
//
//  Created by 최우석 on 2023/03/09.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int A, B, value;
    cout << "Please enter two integer values: " << endl;
    cout << "A : ";
    cin >> A;
    cout << "B : ";
    cin >> B;
    value = A;
    A = B;
    B = value;
    cout << "value of A is : " << A << endl;
    cout << "value of B is : " << B << endl;
    
    return 0;
}
