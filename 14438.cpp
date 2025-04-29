#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> num;
vector<int> tree;

void input() {
    cin >> N;
    num.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> num[i];
    }
    cin >> M;
}

void makeTree(int node, int start, int end) {
    if (start == end) tree[node] = num[start];
    else {
        makeTree(node*2, start, (start+end)/2);
        makeTree(node*2+1, (start+end)/2+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

void init() {
    tree.resize(4*N+1);
    makeTree(1, 1, N);
}

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;
    if (start == end) tree[node] = val;
    else {
        update(node*2, start, (start+end)/2, idx, val);
        update(node*2+1, (start+end)/2+1, end, idx, val);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return INT32_MAX;
    if (left <= start && end <= right) return tree[node]; 
    int lval = query(node*2, start, (start+end)/2, left, right);
    int rval = query(node*2+1, (start+end)/2+1, end, left, right);
    return min(lval, rval);
}

void solve() {
    init();
    int op, a, b;
    for (int i=0; i<M; i++) {
        cin >> op >> a >> b;
        if (op == 1) update(1, 1, N, a, b);
        else cout << query(1, 1, N, a, b) << '\n';
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