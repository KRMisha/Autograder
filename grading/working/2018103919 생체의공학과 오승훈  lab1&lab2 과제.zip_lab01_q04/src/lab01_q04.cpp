#include <iostream>
using namespace std;

//sizeof()의 기능은 자료형의 size를 알려주는 것이다.
int main(void)
{
	const float PI=3.14;
	char ch1 = 65;
	char ch2 =ch1+32;
	cout << PI << endl;
	cout << ch1 << endl;
	cout << ch2 << endl;

	return 0;
}
