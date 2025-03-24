// batch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream inputFile("batch.inp");//파일 읽기 std::ifstream inputFile();
	ofstream outputFile("batch.out");//파일 쓰기 std::ofstream outputFile();
	int N = 0;
	inputFile >> N;//프로그램 수
	vector<vector<int>> batch_time(N);

	int cpu_total_time = 0;
	int cpu_idle_time = 0;
	
	for (int i = 0; i < N; i++) {
		int num;
		while (inputFile >> num && num != -1) {  // -1이 나올 때까지 읽기
			batch_time[i].push_back(num);
		}
	}


	for (int j = 0; j < N;j++) {
		for (size_t i = 0; i < batch_time[j].size(); i++) {
			cpu_total_time += batch_time[j][i];
			if (i % 2 == 1) {//짝수 번째 원소; I/O time ; cpu유휴 시간
				cpu_idle_time += batch_time[j][i];
			}
		}
	}

	outputFile << cpu_idle_time << " " << cpu_total_time;
	
	inputFile.close();
	outputFile.close();

}
