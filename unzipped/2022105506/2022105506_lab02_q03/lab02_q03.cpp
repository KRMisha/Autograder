/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int i1 = 2, i2 = 5, i3 = -3;
    double d1 = 2.0, d2 = 5.0, d3 = -0.5;
    
    
    cout<< i1 + (i2*i3) << endl;
    cout<< i1 * (i2+i3) << endl;
    cout<< i1 / (i2+i3) << endl;
    cout<< i1 / i2+i3 << endl;
    cout<< 3 + 4+ 5/ 3 << endl;
    cout<< (3 + 4+ 5)/ 3 << endl;
    cout<< d1 + (d2 * d3)<< endl;
    cout<< d1 + d2 * d3<< endl;
    cout<< d1 / d2 - d3<< endl;
    cout<< d1 / (d2 - d3)<< endl;
    cout<< d1 + d2 + d3/3<< endl;
    cout<< (d1 + d2 + d3)/3<< endl;
    
    
    return 0;
}


