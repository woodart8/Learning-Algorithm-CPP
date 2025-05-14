#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<long long> tree;

void update(int node, int start, int end, int idx, int val) {
    if (idx > end || idx < start) return;
    if (start == end) tree[node] = val;
    else {
        update(node*2, start, (start+end)/2, idx, val);
        update(node*2+1, (start+end)/2+1, end, idx, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    long long lval = query(node*2, start, (start+end)/2, left, right);
    long long rval = query(node*2+1, (start+end)/2+1, end, left, right);
    return lval + rval;
}

void init() {
    cin >> N >> Q;
    tree.resize(4*N);
    for (int i=1; i<=N; i++) {
        int num;
        cin >> num;
        update(1, 1, N, i, num);
    }
}

void solve() {
    for (int i=1; i<=Q; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << query(1, 1, N, x, y) << '\n';
        update(1, 1, N, a, b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}