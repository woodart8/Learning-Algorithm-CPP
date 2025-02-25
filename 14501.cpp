#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<int> t;
vector<int> p;
int dp[16];

int main() {
    cin >> N;

    t.resize(N+1);
    p.resize(N+1);

    for (int i=1; i<=N; i++) {
        cin >> t[i] >> p[i];
        if (i + t[i] > N+1) {
            p[i] = 0;
        }
        dp[i] = p[i];
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<i; j++) {
            if (j+t[j] > i) continue;
            dp[i] =  max(dp[i], dp[j] + p[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}