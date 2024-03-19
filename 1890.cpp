#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[101][101];
long long dp[101][101];

long long dfs(int x, int y) {
    if(x > N || y > N) return 0;
    if(x == N && y == N) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    int nx = x + map[x][y];
    int ny = y + map[x][y];
    dp[x][y] = dp[x][y] + dfs(nx, y) + dfs(x, ny);
    return dp[x][y];
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }

    cout << dfs(1,1);
    return 0;
}