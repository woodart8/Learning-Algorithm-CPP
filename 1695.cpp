#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> a;
int dp[5001][5001];

int solve(int l, int r) {
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    if(a[l] == a[r]) dp[l][r] = solve(l+1, r-1);
    else dp[l][r] = min(solve(l+1, r), solve(l, r-1)) + 1;
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    a.resize(N+1);
    for(int i=1; i<=N; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(1, N) << endl;
    return 0;
}