//
//  main.cpp
//  q5
//
//  Created by 김우진 on 2023/03/09.
//

#include <iostream>
using namespace std;
int main() {
    int x, y, sum, mult;
    
    float div;
    cin >> x >> y;
    sum = x+y;
    mult = x*y;
    div = x/y;
    cout << x << '\t' << y << endl;
    cout << "x + y = " << sum << endl;
    cout << "x * y = " << mult << endl;
    cout << "x / y = " << div << endl;
}
