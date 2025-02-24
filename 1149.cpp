#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1001][3];
int dp[1001][3];

int main() {
    cin >> N;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<3; j++) {
            cin >> cost[i][j];
        }
    }

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for (int i=2; i<=N; i++) {
        for (int j=0; j<3; j++) {
            dp[i][j] = min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3])+cost[i][j];
        }
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]) << '\n';

    return 0;
}