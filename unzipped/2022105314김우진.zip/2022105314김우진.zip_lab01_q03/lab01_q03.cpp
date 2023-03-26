//
//  main.cpp
//  q3
//
//  Created by 김우진 on 2023/03/09.
//

#include <iostream>
using namespace std;

int main() {
    int a, b, c, d,e;
    a=((7==5)? 1:0);
    b=(7>=5)? 1:0;
    c=(7!=5)? 1:0;
    d=(7<=5)? 1:0;
    e=(7>=5)? 100:-100;
cout << "(7 == 5):" << a<< endl;
cout << "(7 >= 5):" <<  b<< endl;
cout << "(7 != 5):" <<  c<< endl;
cout << "(7 <= 5):" <<  d<< endl;
cout << "(7 >= 5 ? 100 : -100): " << e << endl;

}
