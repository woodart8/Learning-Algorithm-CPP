#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[100001];

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        int num;
        cin >> num;
        dp[i] = max(dp[i-1]+num, num);
    }

    int ans = INT32_MIN;
    for(int i=1; i<=N; i++) {
        ans = max(dp[i],ans);
    }
    cout << ans << '\n';
    return 0;
}