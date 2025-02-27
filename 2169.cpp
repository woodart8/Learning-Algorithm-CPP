#include <iostream>
#include <queue>

using namespace std;

int N,M;
int mars[1001][1001];
int mem[1001][1001][2];
int dp[1001][1001];
bool visited[1000][1000];
int dx[] = {0, 0, 1};
int dy[] = {-1, 1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> mars[i][j];
        }
    }

    for (int j=1; j<=M; j++) {
        dp[1][j] = dp[1][j-1] + mars[1][j];
    }

    for (int i=2; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            mem[i][j][0] = dp[i-1][j] + mars[i][j];
            mem[i][j][1] = dp[i-1][j] + mars[i][j];
        }

        for (int j=2; j<=M; j++) {
            mem[i][j][0] = max(mem[i][j][0], mem[i][j-1][0] + mars[i][j]); 
        }

        for (int j=M-1; j>=1; j--) {
            mem[i][j][1] = max(mem[i][j][1], mem[i][j+1][1] + mars[i][j]);
        }

        for (int j=1; j<=M; j++) {
            dp[i][j] = max(mem[i][j][0], mem[i][j][1]);
        }
    }

    cout << dp[N][M] << '\n';

    return 0;
}