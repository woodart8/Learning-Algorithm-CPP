#include <iostream>

using namespace std;

int N;
int dp[100001];

int main() {
    cin >> N;

    int ans = INT32_MIN;
    for (int i=1; i<=N; i++) {
        cin >> dp[i];
        dp[i] = max(dp[i], dp[i] + dp[i-1]);
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}