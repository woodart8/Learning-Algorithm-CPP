#include <iostream>
#include <vector>

using namespace std;

int T, N;
long long dp[101];

int main(){
    cin >> T;

    dp[1] = 1;
    dp[2] = 1;
    for (int i=3; i<=100; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }

    while(T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}
