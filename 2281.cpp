#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n,m;
vector<int> name(1000, 0);
vector<int> dp(1000, INT32_MAX); 


int solve(int i) {
    if(dp[i] < INT32_MAX) return dp[i];

    int remain = m - name[i];
    for(int k=i+1; k<=n && remain >= 0; k++) {
        if(k==n) {
            dp[i] = 0;
            break; 
        }
        dp[i] = min(dp[i], remain * remain + solve(k));
        remain -= name[k]+1;
    }
    return dp[i];
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> name[i];
    }

    dp[n-1] = 0;
    cout << solve(0) << endl;
    return 0;
}