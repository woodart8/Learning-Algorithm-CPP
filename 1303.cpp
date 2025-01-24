#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
char map[100][100];
bool visited[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int ans[] = {0, 0};

void input() {
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
}

int bfs(int x, int y, char ch) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    int cnt = 1; 

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[nx][ny]) continue;
            if (map[nx][ny] != ch) continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
            cnt++;
        }
    }

    return cnt * cnt;
}

void solve() {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j]) continue;
            map[i][j] == 'W' ? ans[0] += bfs(i,j, map[i][j]) : ans[1] += bfs(i,j, map[i][j]);
        }
    }

    cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}