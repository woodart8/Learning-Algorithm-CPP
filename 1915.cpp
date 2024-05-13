#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

char map[1001][1001];
int dp[1001][1001];
int N,M;
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> map[i][j];
            if(map[i][j] == '1') {
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]))+1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans*ans << '\n';
    return 0;
}