#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

void input() {
    cin >> N;
}

void solve() {
    int cnt = 0;
    while (N) {
        if (N%2) {
            cnt++;
        }
        N/=2;
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}