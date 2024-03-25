#include <iostream>
#include <algorithm>
using namespace std;

int N;
int map[100001][3];
int dp[3][2];

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<3; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<3; i++) {
        dp[i][0] = dp[i][1] = map[1][i];
    }
    
    int temp[3][2];
    for(int i=2; i<=N; i++) {
        for(int j=0; j<3; j++) {
            temp[j][0] = dp[j][0];
            temp[j][1] = dp[j][1];
        }
        for(int j=0; j<3; j++) {
            if(j == 0) {
                dp[j][0] = min(map[i][j]+temp[j][0], map[i][j]+temp[j+1][0]);
                dp[j][1] = max(map[i][j]+temp[j][1], map[i][j]+temp[j+1][1]);
            }
            else if(j == 1) {
                dp[j][0] = min(map[i][j]+temp[j-1][0], min(map[i][j]+temp[j][0], map[i][j]+temp[j+1][0]));
                dp[j][1] = max(map[i][j]+temp[j-1][1], max(map[i][j]+temp[j][1], map[i][j]+temp[j+1][1]));
            }  
            else {
                dp[j][0] = min(map[i][j]+temp[j-1][0], map[i][j]+temp[j][0]);
                dp[j][1] = max(map[i][j]+temp[j-1][1], map[i][j]+temp[j][1]);
            }
        }
    }
    int ans_min = 1e9;
    int ans_max = 0;
    for(int i=0; i<3; i++) {
        ans_min = min(ans_min, dp[i][0]);
        ans_max = max(ans_max, dp[i][1]);    
    }
    cout << ans_max << ' ' << ans_min;
    return 0;
}