#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> tree;

void input() {
    cin >> N >> M;
}

void init() {
    tree.resize(4*N+1);
}

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;
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

void solve() {
    init();
    int op, a, b;
    for (int i=0; i<M; i++) {
        cin >> op >> a >> b;
        if (op == 1) update(1, 1, N, a, b);
        else {
            if (a > b) swap(a, b);
            cout << query(1, 1, N, a, b) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}