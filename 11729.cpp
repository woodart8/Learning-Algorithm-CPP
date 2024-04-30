#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int N;
// int dp[21];

void hanoi(int start, int mid, int end, int n) {
    if(n == 1) {
        cout << start << ' ' << end << endl;
        return;
    }
    hanoi(start, end, mid, n-1);
    cout << start << ' ' << end << endl;
    hanoi(mid, start, end, n-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    /*
    dp[1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1]*2 + 1;
    } 
    // ex: 1번에서 3번으로 N개 이동 = 
    // 1번에서 2번으로 N-1개 이동 + 1번에서 3번으로 1개 이동 + 2번에서 3번으로 N-1개 이동
    cout << dp[N] << endl;
    */

    cout << (1<<N)-1 << endl;

    hanoi(1,2,3,N);
    return 0;
}