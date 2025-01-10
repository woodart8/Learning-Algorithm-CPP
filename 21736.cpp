#include <iostream>
#include <queue>

using namespace std;

int N,M;
int initX, initY;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char map[600][600];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'I') {
                initX = i, initY = j;
                break;
            }
        }
    }
}

void solve() {
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({initX,initY});
    map[initX][initY] = 'X';

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 'X') continue;
            if (map[nx][ny] == 'P') cnt++;

            q.push({nx,ny});
            map[nx][ny] = 'X';
        }
    }

    cnt ? cout << cnt : cout << "TT";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}