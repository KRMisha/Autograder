#include <iostream>
using namespace std;
//sizeof 함수를 사용하면 변수나 자료형의 크기를 알 수 있다.
int main() {
	cout << "(7 == 5):" << (7==5 ? 1:0) << endl;
	cout << "(7 >= 5):" << (7>=5 ? 1:0) <<endl;
	cout << "(7 != 5):" << (7!=5 ?1:0) << endl;
	cout << "(7 >= 5 ? 100 : -100): "<< (7 >= 5 ? 100 : -100) <<endl;
}