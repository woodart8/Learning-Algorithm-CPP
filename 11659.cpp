#include <iostream>
#include <vector>
using namespace std;

int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<long> dp(n+1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        long num;
        cin>>num;
        dp[i] = dp[i-1]+num;
    }
    for(int i=0; i<m; i++){
        int s, e;
        cin>>s>>e;
        cout<<dp[e]-dp[s-1]<<'\n';
    }
}