#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> schedule;
int dp[16];
int table[16];
int ans;

int main() {
    cin >> N;
    schedule.push_back({0,0});
    for(int i=0; i<N; i++) {
        int t, p;
        cin >> t >> p;
        schedule.push_back({t,p});
        table[i+1] = i+1 + t; 
    }   

    for(int i=1; i<=N; i++) {
        if(table[i] > N+1) continue;
        dp[i] = schedule[i].second;
        int temp = dp[i];
        for(int j=1; j<=i-1; j++) {
            if(table[j] > i) continue;
            dp[i] = max(dp[i], temp+dp[j]);
        }
    }

    for(int i=1; i<=N; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}