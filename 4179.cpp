#include <iostream>
#include <queue>

using namespace std;

int R, C;
char miro[1000][1000];
int visited[1000][1000]; // 사람 방문
int fire_visited[1000][1000]; // 불 퍼짐 시간
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> jq, fq;

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> miro[i][j];
            visited[i][j] = -1;
            fire_visited[i][j] = -1;
            if (miro[i][j] == 'J') {
                jq.push({i, j});
                visited[i][j] = 0;
            }
            if (miro[i][j] == 'F') {
                fq.push({i, j});
                fire_visited[i][j] = 0;
            }
        }
    }
}

void solve() {
    // 불 먼저 BFS로 퍼뜨리기
    while (!fq.empty()) {
        int x = fq.front().first;
        int y = fq.front().second; 
        fq.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (miro[nx][ny] == '#' || fire_visited[nx][ny] >= 0) continue;
            fire_visited[nx][ny] = fire_visited[x][y] + 1;
            fq.push({nx, ny});
        }
    }

    // 사람 이동
    while (!jq.empty()) {
        int x = jq.front().first;
        int y = jq.front().second; 
        jq.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 밖이면 탈출 성공
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << visited[x][y] + 1 << '\n';
                return;
            }

            if (miro[nx][ny] == '#' || visited[nx][ny] >= 0) continue;

            // 불이 이미 도달했거나 동시에 도달하는 경우 이동 불가
            if (fire_visited[nx][ny] != -1 && fire_visited[nx][ny] <= visited[x][y] + 1) continue;

            visited[nx][ny] = visited[x][y] + 1;
            jq.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}