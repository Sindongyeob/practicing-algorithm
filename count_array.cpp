#include <iostream>
using namespace std;

// N���� ����(1�̻�100����)�� ������ �迭�� �Է¹ް� Ư�� ���� ��� �ִ��� ���� ��ȯ

namespace mystd {
	int count(int* first, int* last, const int& val);//first �迭 ���� �ּ� last �迭 ������ �ּ� val�� ���� �����
}

int mystd::count(int* first, int* last, const int& val) {
	int count = 0;
	while (first != last) {
		if (*first == val) {
			count++;
		}
		first++;
	}
	return count;
}

int main() {
	int a[100] = { 0 };
	int n, s, e, k = 0;
	cin >> n >> s >> e >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout<<mystd::count(a+s-1,a+e-1,k);

	return 0;
}


