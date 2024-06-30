#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int dp[1000][2];
int ans;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for(int i=0; i<N; i++) {
        dp[i][0] = 1;
        for(int j=0; j<i; j++) {
            if(v[j] < v[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0]+1);
            }
        }
    }

    for(int i=N-1; i>=0; i--) {
        dp[i][1] = 1;
        for(int j=N-1; j>i; j--) {
            if(v[j] < v[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1]+1);
            }
        }
    }

    for(int i=0; i<N; i++) {
        ans = max(ans, dp[i][0]+dp[i][1]-1);
    }
    cout << ans << '\n';
    return 0;
}