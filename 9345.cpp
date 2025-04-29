#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K;

void makeTree(vector<int> &tree, const vector<int> &dvd, int node, int start, int end, bool flag) {
    if (start == end) tree[node] = dvd[start];
    else {
        makeTree(tree, dvd, node*2, start, (start+end)/2, flag);
        makeTree(tree, dvd, node*2+1, (start+end)/2+1, end, flag);
        tree[node] = flag ? min(tree[node*2], tree[node*2+1]) : max(tree[node*2], tree[node*2+1]);
    }
}

void update(vector<int> &tree, int node, int start, int end, int idx, int val, bool flag) {
    if (idx < start || idx > end) return;
    if (start == end) tree[node] = val;
    else {
        update(tree, node*2, start, (start+end)/2, idx, val, flag);
        update(tree, node*2+1, (start+end)/2+1, end, idx, val, flag);
        tree[node] = flag ? min(tree[node*2], tree[node*2+1]) : max(tree[node*2], tree[node*2+1]);
    }
}

int query(vector<int> &tree, int node, int start, int end, int left, int right, bool flag) {
    if (left > end || right < start) return flag ? 1e9 : 0;
    if (left <= start && end <= right) return tree[node];
    int lval = query(tree, node*2, start, (start+end)/2, left, right, flag);
    int rval = query(tree, node*2+1, (start+end)/2+1, end, left, right, flag);
    return flag ? min(lval, rval) : max(lval, rval);
}

void init(vector<int> &dvd, vector<int> &minTree, vector<int> &maxTree) {
    dvd.resize(N);
    for (int i=0; i<N; i++) {
        dvd[i] = i;
    }

    minTree.resize(4*N+1);
    maxTree.resize(4*N+1);

    makeTree(minTree, dvd, 1, 0, N-1, true);
    makeTree(maxTree, dvd, 1, 0, N-1, false);
}

void solve() {
    vector<int> dvd;
    vector<int> minTree;
    vector<int> maxTree;

    init(dvd, minTree, maxTree);

    int Q, A, B;
    for (int i=0; i<K; i++) {
        cin >> Q >> A >> B;
        if (Q == 0) {
            update(minTree, 1, 0, N-1, A, dvd[B], true);
            update(minTree, 1, 0, N-1, B, dvd[A], true);
            update(maxTree, 1, 0, N-1, A, dvd[B], false);
            update(maxTree, 1, 0, N-1, B, dvd[A], false);
            swap(dvd[A], dvd[B]);
        } else {
            int minVal = query(minTree, 1, 0, N-1, A, B, true);
            int maxVal = query(maxTree, 1, 0, N-1, A, B, false);
            if (minVal == A && maxVal == B) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> K;
        solve();
    }

    return 0;
}