#include <iostream>

using namespace std;

int N,M;
int seat[41];
int dp[41];
int ans = 1;

int main() {
    cin >> N >> M;
    for(int i=1; i<=M; i++) {
        int num;
        cin >> num;
        seat[num] = num;
    }

    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }

    int count = 0;
    for(int i=1; i<=N; i++) {
        if(seat[i]==0) count++;
        else {
            if(count==0) continue;
            ans *= dp[count];
            count = 0;
        }
    }

    if(count > 0) ans *= dp[count];
    cout << ans << endl;
    return 0;
}