#include <iostream>
#include <vector>

using namespace std;

int N;
bool map[17][17];
int dp[3][17][17];

void Input() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }
}

int Solve() {
    dp[0][1][2] = 1;
    for(int i=3; i<=N; i++) {
        if(!map[1][i]) dp[0][1][i] = dp[0][1][i-1];
    }
    
    for(int i=2; i<=N; i++) {
        for(int j=3; j<=N; j++) {
            if(map[i][j]) continue;
            dp[0][i][j] = dp[0][i][j-1] + dp[1][i][j-1];
            dp[2][i][j] = dp[1][i-1][j] + dp[2][i-1][j];

            if(!map[i-1][j] && !map[i][j-1])
                dp[1][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
        }
    }
    
    int ret = 0;
    for(int i=0; i<3; i++) {
        ret += dp[i][N][N];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Input();
    cout << Solve();
    return 0;
}