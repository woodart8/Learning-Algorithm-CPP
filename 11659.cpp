#include <iostream>

using namespace std;

int n,m;
int dp[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    for (int i=1; i<=n; i++) {
        int num;
        cin >> num;
        dp[i] = num + dp[i-1];
    }

    for (int i=1; i<=m; i++) {
        int s,e;
        cin >> s >> e;
        cout << dp[e] - dp[s-1] << '\n';
    }
}