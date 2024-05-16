#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    while(T--){
        long long ans = 0;
        cin >> N;
        for(int i=0; i<N; i++) {
            long long num;
            cin >> num;
            pq.emplace(num);
        }

        while(pq.size() > 1) {
            long long x = pq.top(); pq.pop();
            x += pq.top(); pq.pop();
            ans += x;
            pq.emplace(x);
        }
        pq.pop();
        cout << ans << '\n';
    }
    return 0;
}