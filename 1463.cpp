#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i=0; i<=N; i++) {
        dp[i] = 1e9;
    }

    dp[1] = 0;

    for (int i=2; i<=N; i++) {
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        } 
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }

        dp[i] = min(dp[i], dp[i-1] + 1);
    }

    cout << dp[N] << '\n';

    return 0;
}