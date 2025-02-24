#include <iostream>

using namespace std;

int n;
int dp[301][2];
int val[301];

int main(){
    cin>>n;

    for (int i=1; i<=n; i++) {
        cin >> val[i];
    }

    dp[1][0] = dp[1][1] = val[1];

    for (int i=2; i<=n; i++) {
        dp[i][0] = val[i] + dp[i-1][1];
        dp[i][1] = val[i] + max(dp[i-2][0],dp[i-2][1]);
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
    
}