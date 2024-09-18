#include <iostream>
using namespace std;

// N개의 정수(1이상100이하)를 일차원 배열에 입력받고 특정 값이 몇개가 있는지 세어 반환

namespace mystd {
	int count(int* first, int* last, const int& val);//first 배열 시작 주소 last 배열 마지막 주소 val의 값이 몇개인지
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


