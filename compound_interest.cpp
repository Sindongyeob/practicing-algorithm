#include <iostream>
using namespace std;


/*
* 5%의 이율로 복리이자, 현재 m원, n년 동안 복리 계산
*/
void compound_interest_calc() {
	double n, m;
	cout << "첫날 저금할 돈:";
	cin >> m;
	cout << "몇 년동안 복리계산할지:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		m = m * 1.05;
		cout.precision(2);
		cout<< fixed << m << endl;
	}
}

int main() {
	compound_interest_calc();
	return 0;
}