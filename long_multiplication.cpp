#include <iostream>
using namespace std;

/*
* 두 개의 수 A,B가 주어지면 학교에서 배운 방식으로 두 수 A와B의 곱셈을 하는 과정을 출력하여라
*/
void long_multiplication() {
	int a, b;
	cin >> a >> b;
	if ((a >= 100 || a <= 999) && (b >= 100 || b <= 999)) {
		cout.width(6);
		cout << a << endl;
		cout.width(6);
		cout << b << endl;
		cout << "______" << endl;

		int b1, b10, b100 = 0;
		int ab = a * b;
		b100 = b / 100;
		b = b%100;
		b10 = b /10;
		b = b%10;
		b1 = b;

		cout.width(6);
		cout << b1 * a << endl;
		cout.width(5);
		cout << b10 * a << endl;
		cout.width(4);
		cout <<b100 * a << endl;
		cout << "______"<< endl;
		cout << ab;
	}
	else {
		cout << "입력 범위 초과";
		exit(0);
	}
}