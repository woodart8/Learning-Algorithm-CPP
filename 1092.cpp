#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N,M;
vector<int> cranes;
multiset<int> boxes;

void input() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int limit;
        cin >> limit;
        cranes.push_back(limit);
    }

    cin >> M;
    for (int i=0; i<M; i++) {
        int weight;
        cin >> weight;
        boxes.insert(weight);
    }
}

void solve() {
    sort(cranes.begin(), cranes.end(), greater<int>());

    if (*boxes.rbegin() > cranes[0]) {
        cout << -1 << '\n';
        return;
    }

    int T = 0;
    while (!boxes.empty()) {
        for (int crane : cranes) {
            auto it = boxes.upper_bound(crane);
            if (it == boxes.begin()) break;
            boxes.erase(prev(it));
        }
        T++;
    }

    cout << T << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
    return 0;
}