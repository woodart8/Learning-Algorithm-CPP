#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int dp[1000];

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        dp[i] = num;
    }

    int ans = dp[0];
    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j]+v[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}