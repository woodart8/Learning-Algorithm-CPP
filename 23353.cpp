#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[1001][1001];
int dp[1002][1002][4][2]; 
// i,j -> 좌표
// k -> 0:왼, 1:왼대각, 2:위, 3:오른대각
// l -> 백돌을 흑돌로 바꾼 횟수

void input() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> board[i][j];
        }
    }
}

void solve() {
    int answer = 0;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (board[i][j] == 0) continue;
            else if (board[i][j] == 1) {
                for (int l=0; l<=1; l++) {
                    dp[i][j][0][l] = dp[i][j-1][0][l] + 1;
                    dp[i][j][1][l] = dp[i-1][j-1][1][l] + 1;
                    dp[i][j][2][l] = dp[i-1][j][2][l] + 1;
                    dp[i][j][3][l] = dp[i-1][j+1][3][l] + 1;
                }
            } else {
                dp[i][j][0][1] = board[i][j-1] == 2 ?  1 : dp[i][j-1][0][0] + 1;
                dp[i][j][1][1] = board[i-1][j-1] == 2 ? 1 : dp[i-1][j-1][1][0] + 1;
                dp[i][j][2][1] = board[i-1][j] == 2 ? 1 : dp[i-1][j][2][0] + 1;
                dp[i][j][3][1] = board[i-1][j+1] == 2 ? 1 : dp[i-1][j+1][3][0] + 1;
            }
        }
    }

    for (int k=0; k<4; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                answer = max(answer, dp[i][j][k][1]);
            } 
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}