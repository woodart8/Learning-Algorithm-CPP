#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int dp[10001];

int main() {
    cin >> N;

    int l;
    v.push_back(0);
    for(int i=1 ; i<=N; i++) {
        cin >> l;
        v.push_back(l);
    }

    dp[1] = v[1];
    dp[2] = v[1]+v[2];

    for(int i=3; i<=N; i++) {
        dp[i] = max(max(dp[i-1], dp[i-2]+v[i]), dp[i-3]+v[i-1]+v[i]);
    }

    cout << dp[N] << endl;

    return 0;
}