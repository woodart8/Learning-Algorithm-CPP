#include <iostream>
#include <queue>

using namespace std;

class State {
	public:
		int rx, ry;
		int bx, by;
		int count;

		State(int _rx, int _ry, int _bx, int _by, int _count) {
			this->rx = _rx;
			this->ry = _ry;
			this->bx = _bx;
			this->by = _by;
			this->count = _count;
		}
};

int N, M;
int irx, iry, ibx, iby; // 초기 구슬 위치
char map[11][11];
bool visited[11][11][11][11]; // State 방문 여부
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

// 기울이기
void move(int& rx, int& ry, int& distance, int& i) {
	while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O') {
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}

void bfs(State state) {
	queue<State> q;
	q.push(state);
	visited[state.rx][state.ry][state.bx][state.by] = true;
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int count = q.front().count;
		q.pop();

		// 이동 횟수가 10번이 넘을 경우 break
		if (count >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncount = count + 1;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			// 파란 구슬이 구멍에 빠지면 실패
			if (map[nbx][nby] == 'O') continue;

			// 빨간 구슬이 구멍에 빠지면 성공
			if (map[nrx][nry] == 'O') {
				cout << ncount;
				return;
			}

			// 둘이 겹칠경우 이전 위치 고려해서 재배치
			if (nrx == nbx && nry == nby) {
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({nrx,nry,nbx,nby,ncount});
		}
	}
	cout << -1;
}

void input() {
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				irx = i; iry = j;
			} else if (map[i][j] == 'B') {
				ibx = i; iby = j;
			}
		}
	}
}

void solve() {
	State state(irx, iry, ibx, iby, 0);
	bfs(state);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
	return 0;
}