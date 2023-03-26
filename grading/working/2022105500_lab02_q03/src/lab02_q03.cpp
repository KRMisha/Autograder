//
//  main.cpp
//  sol_extend_3
//
//  Created by 최우석 on 2023/03/09.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int i1 = 2, i2 = 5, i3 = -3;
    double d1 = 2.0, d2 = 5.0, d3 = -0.5;
    
    cout << i1 + (i2 * i3) << endl;
    cout << i1 * (i2 + i3) << endl;
    cout << i1 / (i2 + i3) << endl;
    cout << i1 / i2 + i3 << endl;
    cout << 3 + 4 + 5 / 3 << endl;
    cout << (3 + 4 + 5) / 3 << endl;
    cout << d1 + (d2 * d3) << endl;
    cout << d1 + d2 * d3 << endl;
    cout << d1 / d2 - d3 << endl;
    cout << d1 / (d2 - d3) << endl;
    cout << d1 + d2 + d3 / 3 << endl;
    cout << (d1 + d2 + d3) / 3 << endl;
    return 0;
}
