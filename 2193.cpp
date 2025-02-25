#include <iostream>

using namespace std;

int N;
long long dp[91];

int main() {
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N] << '\n';
    return 0;
}