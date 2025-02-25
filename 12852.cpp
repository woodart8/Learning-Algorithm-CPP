#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp[1] = 0;
    for (int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + 1;
        if (i%3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        if (i%2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }

    cout << dp[N] << '\n';

    vector<int> path;
    int t = N;
    while(t > 0) {
        path.push_back(t);
        int b = dp[t-1];
        int next = t-1;
        if (t%3 == 0 && dp[t/3] < b) {
            b = dp[t/3];
            next = t/3;
        }
        if (t%2 == 0 && dp[t/2] < b) {
            b = dp[t/2];
            next = t/2;
        }
        t = next;
    }

    for (int a : path) {
        cout << a << ' ';
    }

    return 0;
}