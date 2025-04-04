#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1001][3]; // 집을 칠하는 비용
int dp[1001][3]; // dp[i][j] : i번째 집을 j 색상으로 칠할 때, 누적 비용의 최솟값

void input() {
    cin >> N;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<3; j++) {
            cin >> cost[i][j];
        }
    }
}

void solve() {
    for (int i=0; i<3; i++) {
        dp[1][i] = cost[1][i];
    }

    for (int i=2; i<=N; i++) {
        for (int j=0; j<3; j++) {
            dp[i][j] = min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+cost[i][j];
        }
    } 
    // i번째 집을 j 색상으로 칠할 경우 i-1번째 집은 (j+1)%3 or (j+2)%3 색상이어야한다.
    // 따라서 dp[i][j] = min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+cost[i][j];

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}