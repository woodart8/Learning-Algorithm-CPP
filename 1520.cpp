#include <iostream>
#include <cstring>
using namespace std;

int M,N;
int h[501][501];
int dp[501][501];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if(x == M && y == N) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > M || ny > N) continue;
        if(h[nx][ny] < h[x][y]) dp[x][y] += dfs(nx,ny);
    }

    return dp[x][y];
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> M >> N;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            cin >> h[i][j];
        }
    }

    cout << dfs(1,1) << endl;
    return 0;
}