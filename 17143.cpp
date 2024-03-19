#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 105
#define LL long long
#define INF 1e9

using namespace std;
struct SHARK {
	int R, C, S, D, Z;
	bool isLive = true;
};

int R, C, M;
vector<SHARK> Shark;
int Fisher = 0;
int MAP[MAX][MAX];
int moveY[5] = { 0,-1,1,0,0 };
int moveX[5] = { 0,0,0,1,-1 };
int answer = 0;

void Shark_Moving(int IDX) {
	int Len = Shark[IDX].S;
	int Dir = Shark[IDX].D;
	int Y = Shark[IDX].R;
	int X = Shark[IDX].C;
	if ((Dir == 1) || (Dir == 2)) { // 상어가 위아래로 움직이는 경우
		Len %= ((R - 1) * 2);
	}
	else if ((Dir == 3) || (Dir == 4)) { // 상어가 좌우로 움직이는 경우
		Len %= ((C - 1) * 2);
	}
	while (Len--) {
		int nextY = Y + moveY[Dir];
		int nextX = X + moveX[Dir];
		if ((nextY < 1) || (nextY > R) || (nextX < 1) || (nextX > C)) {
			if (Dir == 1) {
				Dir = 2;
			}
			else if (Dir == 2) {
				Dir = 1;
			}
			else if (Dir == 3) {
				Dir = 4;
			}
			else if (Dir == 4) {
				Dir = 3;
			}
			nextY = Y + moveY[Dir];
			nextX = X + moveX[Dir];
		}
		Y = nextY;
		X = nextX;
	};
	Shark[IDX].D = Dir;
	Shark[IDX].R = Y;
	Shark[IDX].C = X;
	MAP[Y][X]++;
}

void Shark_Eating(int Y, int X) {
	int Big = -1;
	int Big_IDX = 0;
	for (int i = 1; i <= M; i++) {
		if ((Shark[i].isLive) && (Shark[i].R == Y) && (Shark[i].C == X)) {
			if (Big < Shark[i].Z) {
				Big = Shark[i].Z;
				Big_IDX = i;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		if ((Shark[i].isLive) && (Shark[i].R == Y) && (Shark[i].C == X)) {
			if (Big != Shark[i].Z) {
				Shark[i].isLive = false;
			}
		}
	}
	MAP[Y][X] = 1;
}

int main() {
	FIRST
	cin >> R >> C >> M;
	Shark.resize(M + 1);
	for (int i = 1; i <= M; i++) {
		int R, C, S, D, Z;
		cin >> Shark[i].R >> Shark[i].C >> Shark[i].S >> Shark[i].D >> Shark[i].Z;
		MAP[Shark[i].R][Shark[i].C]++;
	}
	while (1) {
		Fisher++; // 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
		if (Fisher > C) { // 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.
			break;
		}
		for (int i = 1; i <= R; i++) { // 2. 땅과 가장 가까이에 있는 상어를 잡는다고 하였으므로, 1번째 행에서부터 상어를 찾는다.
			if (MAP[i][Fisher] == 1) {
				int Cur_Shark; // 상어의 인덱스
				for (int j = 1; j <= M; j++) {
					if ((Shark[j].isLive) && (Shark[j].R == i) && (Shark[j].C == Fisher)) {
						Cur_Shark = j;
						break;
					}
				}
				Shark[Cur_Shark].isLive = false; // 상어를 잡고
				answer += Shark[Cur_Shark].Z; // 상어를 잡았으면 상어의 크기를 더한다.
				break;
			}
		}
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				MAP[i][j] = 0;
			}
		}
		for (int i = 1; i <= M; i++) {
			if (Shark[i].isLive) { // 살아있는 상어들은 정해진 속력과 이동 방향대로 움직인다.
				int nextY = Shark[i].R + moveY[Shark[i].D];
				int nextX = Shark[i].C + moveX[Shark[i].D];
				Shark_Moving(i);
			}
		}
		// 상어가 2마리 이상 있는 격자는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (MAP[i][j] >= 2) {
					Shark_Eating(i, j);
				}
			}
		}
	};


	cout << answer << "\n";

	return 0;
}