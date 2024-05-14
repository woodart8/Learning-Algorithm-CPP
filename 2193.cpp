#include <iostream>
#include <vector>

using namespace std;

int N;
long long dp[91];
int main() {
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<=N; i++) {
        dp[i] = dp[i-2]+dp[i-1];
    }
    cout << dp[N];
    return 0;
}