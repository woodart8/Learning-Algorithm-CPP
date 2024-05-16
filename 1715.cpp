#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    int num;
    for(int i=0; i<N; i++) {
        cin >> num;
        pq.push(num);
    }

    int ans = 0;
    while(pq.size() > 1) {
        int x = pq.top(); pq.pop();
        x += pq.top(); pq.pop();
        ans += x;
        pq.push(x);
    }
    cout << ans;
    return 0;
}