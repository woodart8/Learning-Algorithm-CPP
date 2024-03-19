#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[31];

int main() {
    cin >> N;
    dp[2] = 3;
    for(int j=4; j<=N; j+=2) {
        dp[j] = dp[2]*dp[j-2]+2;
        for(int i=j-2; i>2; i-=2) {
            dp[j] += dp[j-i]*2;
        }
    }
    cout << dp[N];    
    return 0;
}