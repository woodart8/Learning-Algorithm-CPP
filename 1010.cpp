#include <iostream>
#include <vector>

using namespace std;

int T;
int dp[30][30];
int main() {
    cin >> T;
    for(int i=0; i<=29; i++) {
        dp[0][i] = 1;
    }

    for(int i=1; i<=29; i++) {
        for(int j=i; j<=29; j++) {
            dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
        }
    }

    // for(int i=1; i<=29; i++) {
        // for(int j=1; j<=29; j++) {
            // cout << dp[i][j] << ' ';
        // }
        // cout << '\n';
    // }


    while (T--) {
        int N,M;
        cin >> N >> M;
        cout << dp[N][M] << '\n';
    }
    
    return 0;
}