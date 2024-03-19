#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> coin;
int dp[10001];


int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        int cost;
        cin >> cost;
        coin.push_back(cost);
    }

    for(int i=0; i<coin.size(); i++) {
        if(coin[i] > k) continue;
        dp[coin[i]]++;
        for(int j = coin[i]; j<=k; j++) {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    cout << dp[k] << endl;    
    return 0;
}