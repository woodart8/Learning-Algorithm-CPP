#include <iostream>
using namespace std;

int map[10][10];
// arr[A][B]는 A번째 행에 B라는 숫자가 존재한다는 의미
bool row[10][10] = { false, };
bool col[10][10] = { false, };
bool square[10][10] = { false, };

void print() {
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++)
			cout << map[i][j];
		cout << '\n';
	}
}

void go(int idx) {
	if (idx > 81) {
		print();
		exit(0);
	}
	int x = (idx - 1) / 9 + 1;
	int y = (idx - 1) % 9 + 1;
	int square_num = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
	if (map[x][y] == 0) {
		for(int i = 1; i <= 9; i++) {
			if (row[x][i] == false && col[y][i] == false && square[square_num][i] == false) {
				map[x][y] = i;
				row[x][i] = true;
				col[y][i] = true;
				square[square_num][i] = true;
				go(idx + 1);
				map[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				square[square_num][i] = false;
			}
		}
	}
	else
		go(idx + 1);
}

int main() {
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			scanf("%1d", &map[i][j]);
			row[i][map[i][j]] = true;
			col[j][map[i][j]] = true;
			square[((i - 1) / 3) * 3 + (j - 1) / 3 + 1][map[i][j]] = true;
		}
	}
	go(1);
	return 0;
}