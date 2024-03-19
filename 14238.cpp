#include <iostream>
#include <string>
using namespace std;

int worker[3];//0:A, 1:B, 2:C 입력받은 횟수 저장
bool DP[51][51][51][3][3] = { false, };//A기록 횟수, B기록 횟수, C기록 횟수, 이틀 전 기록, 어제 기록
char res[51];
string S;

bool solution(int a, int b, int c, int pp, int p) {
	if (a == worker[0] && b == worker[1] && c == worker[2])
		return true;
	//이미 구한 거
	if (DP[a][b][c][pp][p])return false;
	DP[a][b][c][pp][p] = true;

	if (a + 1 <= worker[0]) {
		res[a + b + c] = 'A';
		if (solution(a + 1, b, c, p, 0))
			return true;
	}
	if (b + 1 <= worker[1]) {
		res[a + b + c] = 'B';
		if (p != 1 && solution(a, b + 1, c, p, 1))
			return true;
	}
	if (c + 1 <= worker[2]) {
		res[a + b + c] = 'C';
		if (pp != 2 && p != 2 && solution(a, b, c + 1, p, 2))
			return true;
	}
	return false;
}

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A')
			worker[0]++;
		else if (S[i] == 'B')
			worker[1]++;
		else
			worker[2]++;
	}
	if (solution(0, 0, 0, -1, -1))
		for (int i = 0; i < S.size(); i++)
			cout << res[i];
	else
		cout << -1;
	cout << '\n';
	
	return 0;
}