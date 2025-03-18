
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

struct Person {
	string num;
	string firstName;
	string lastName;
};

bool smaller(const Person& a, const Person& b) {
	return a.num < b.num;
}

int main()
{
	ifstream inputFile("test.inp");//파일 읽기 std::ifstream inputFile();
	ofstream outputFile("test.out");//파일 쓰기 std::ofstream outputFile();

	if (!inputFile) {
		cout << "잘못됨";
	}


	int N = 0;
	inputFile >> N;//사람 수

	vector<Person> people(N);

	for (int i = 0; i < N; i++) {
		inputFile >> people[i].num >> people[i].firstName >> people[i].lastName;//한 줄에서 공백을 기준으로 읽어서 배열에 담기
	}

	sort(people.begin(), people.end(), smaller);//num 오름차순으로 정렬

	int largestFirstName = 0;
	for (int i = 0; i < N; i++) {
		if (largestFirstName < people[i].firstName.size()) {
			largestFirstName = people[i].firstName.size();
		}
	}

	largestFirstName++;//공백에 맞추기 위해 1더하기

	for (int i = 0; i < N; i++) {
		outputFile << people[i].num <<" "<< left << setw(largestFirstName)  << people[i].firstName << people[i].lastName << "\n";//std::setw(int n)n만큼 공간 확보 후 작성 기본은 오른쪽 정렬, std::left를 사용해서 왼쪽 정렬로 바꿈

	}

	vector<pair<string, int>> lastNameCount;//lastName과 개수를 같이 저장한 배열

	for (auto& person : people) {
		bool found = false;
		for (auto& start : lastNameCount) {
			if (start.first == person.lastName) {
				start.second++;
				found = true;
				break;
			}
		}
		if (!found) {
			lastNameCount.push_back({ person.lastName, 1 }); // 새로운 lastName이면 추가
		}
	}
	sort(lastNameCount.begin(), lastNameCount.end());
	outputFile << "\n";
	for (auto& tmp : lastNameCount) {
		if (tmp.second > 1) {
			outputFile << tmp.first << " " << tmp.second<<endl;
		}
		
	}

	inputFile.close();
	outputFile.close();

	return 0;

}
