#include <iostream>
using namespace std;


/*
* 5%�� ������ ��������, ���� m��, n�� ���� ���� ���
*/
void compound_interest_calc() {
	double n, m;
	cout << "ù�� ������ ��:";
	cin >> m;
	cout << "�� �⵿�� �����������:";
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