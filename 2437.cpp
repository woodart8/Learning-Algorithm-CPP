#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int dp[1001]; // dp[i] : 1~i번째 추를 사용해 만들 수 있는 최대 무게

void input() {
    cin >> N;
    v.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> v[i];
    }
}

void solve() {
    sort(v.begin(), v.end());
    // EX) 3 1 6 2 7 30 1 -> 1 1 2 3 6 7 30

    // x -> y : x는 사용할 추, y는 x를 사용해 측정할 수 있는 무게
    // i=1 : [1] -> [1]
    // i=2 : [1 1] -> [1 2]
    // i=3 : [1 1 2] -> [1 2 3 4]

    int idx = -1; // dp[i]가 성립하는 마지막 인덱스
    for (int i=1; i<=N; i++) {
        int target = dp[i-1]+1 - v[i]; // i-1번째 y에 존재해야 하는 값
        if (target >= 0 && target <= dp[i-1]) {
            dp[i] = dp[i-1] + v[i];
        } else {
            idx = i-1;
            break;
        }
    }

    if (idx == -1) cout << dp[N]+1;
    else cout << dp[idx]+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}