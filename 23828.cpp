#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int N,M;
vector<int> v;
int cnt[100001];
long long dp[1001][1001];
int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        cnt[num]++;
    }
    for(int i=1; i<=100000; i++) {
        if(cnt[i] > 0) {
            v.push_back(i*cnt[i]);
        }
    }

    for(int i=0; i<=v.size(); i++) {
        dp[0][i] = 1;
    }
    
    for(int i=1; i<=M; i++) {
        for(int j=i; j<=v.size(); j++) {
            dp[i][j] = (dp[i-1][j-1]*v[j-1] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[M][v.size()];
    return 0;
}