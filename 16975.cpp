#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> num;
vector<long long> tree;
vector<long long> lazy;

void input() {
    cin >> N;
    num.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> num[i];
    }
    cin >> M;
}

void makeTree(int node, int start, int end) {
    if (start == end) tree[node] = (long long)num[start];
    else {
        makeTree(node*2, start, (start+end)/2);
        makeTree(node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void init() {
    tree.resize(4*N+1);
    lazy.resize(4*N+1);
    makeTree(1, 1, N);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node]*(end-start+1);
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node]; 
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, int diff) {
    update_lazy(node, start, end);
    if (left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node] += diff*(end-start+1);
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update(node*2, start, (start+end)/2, left, right, diff);
    update(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    long long lsum = query(node*2, start, (start+end)/2, left, right);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

void solve() {
    init();
    int op, a, b, c, x;
    for (int i=0; i<M; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b >> c;
            update(1, 1, N, a, b, c);
        } else {
            cin >> x;
            cout << query(1, 1, N, x, x) << '\n';
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