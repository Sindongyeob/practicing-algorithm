
#include <iostream>
using namespace std;

/*
서식에 맞춰서 날짜를 입력하지 않아도 자동으로 셀 서식에 맞게 날짜를 입력
세 개의 정수를 입력 받아 서식에 맞게 출력하는 프로그램
조건)
year:4자리의 필드 폭을 가지고 우측 정렬하여 출력, 4자리 미만이면 채워지지 않은 빈자리는 0으로 대신
month:2자리의 필드 폭을 가지고 2자리 미만이면 빈자리는 0으로 대신
day:2자리의 필드 폭을 가지고 2자리 미만이면 빈자리는 0으로 대신
ex) input:1 1 1  output:0001-01-01
*/

void print_date() {
	int year, month, day;
	cin >> year >> month >> day;
	if (year >= 1 || year<=9999) {
		cout.width(4);
		cout.fill('0');
		cout << year;
	}
	if (month >= 1 || month<=21) {
		cout << "-";
		cout.width(2);
		cout.fill('0');
		cout << month;
	}
	if (day >= 1 || year<=31) {
		cout << "-";
		cout.width(2);
		cout.fill('0');
		cout << day<<endl;
	}
	else {
		cout << "입력범위를 초과";
		exit(0);
	}
}

int main()
{
	print_date();
	return 0;
}
