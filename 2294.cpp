#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> coin;
vector<int> dp(10001, 1e9);
int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int cost;
        cin >> cost;
        coin.push_back(cost);
    }

    dp[0] = 0;
    for(int i=0; i<coin.size(); i++) {
        if(coin[i] > k) continue;
        for(int j=coin[i]; j<=k; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    if(dp[k] == 1e9) cout << "-1";
    else cout << dp[k];
    return 0;
}