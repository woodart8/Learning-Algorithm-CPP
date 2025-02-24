#include <iostream>
#include <vector>

using namespace std;

int T;
int dp[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i=4; i<=10; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
 
    return 0;
}