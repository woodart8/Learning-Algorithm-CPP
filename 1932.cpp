#include <iostream>

using namespace std;

int N, ans;
int dp[501][501];

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            cin >> dp[i][j];
            dp[i][j] = dp[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}