#include <iostream>
using namespace std;
int main() {
	int i1, i2, i3, ans1, ans2, ans3, ans4, ans5, ans6;
	double d1, d2, d3, ans7, ans8, ans9, ans10, ans11, ans12;
	i1 = 2;
	i2 = 5;
	i3 = -3;
	d1 = 2.0;
	d2 = 5.0;
	d3 = -0.5;
	ans1 = i1 + (i2 * i3);
	ans2 = i1 * (i2 + i3);
	ans3 = i1 / (i2 + i3);
	ans4 = i1 / i2 + i3;
	ans5 = 3 + 4 + 5 / 3;
	ans6 = (3 + 4 + 5) / 3;
	ans7 = d1 + (d2 * d3);
	ans8 = d1 + d2 * d3;
	ans9 = d1 / d2 - d3;
	ans10 = d1 / (d2 - d3);
	ans11 = d1 + d2 + d3 / 3;
	ans12 = (d1 + d2 + d3) / 3;
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;
	cout << ans5 << endl;
	cout << ans6 << endl;
	cout << ans7 << endl;
	cout << ans8 << endl;
	cout << ans9 << endl;
	cout << ans10 << endl;
	cout << ans11 << endl;
	cout << ans12;
}