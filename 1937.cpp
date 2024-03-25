#include <iostream>
#define MAX 501
using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int dp[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n, ans;

int dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for(int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 1 || ny < 1 || nx > n || ny > n || map[nx][ny] <= map[x][y]) continue;
        dp[x][y] = max(dp[x][y], dfs(nx,ny)+1);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            ans = max(ans, dfs(i,j));
        }
    }

    cout << ans << endl;
    return 0;
}