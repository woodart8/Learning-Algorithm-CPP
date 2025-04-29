#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> tree;
vector<int> lazy;

void input() {
    cin >> N >> M;
}

void init() {
    tree.resize(4*N+1);
    lazy.resize(4*N+1);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] = -1 * tree[node] + (end-start+1);
        if (start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if(left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node] = -1 * tree[node] + (end-start+1);
        if (start != end) {
            lazy[node*2] ^= 1;
            lazy[node*2+1] ^= 1;
        }
        return;
    }
    update(node*2, start, (start+end)/2, left, right);
    update(node*2+1, (start+end)/2+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int lsum = query(node*2, start, (start+end)/2, left, right);
    int rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

void solve() {
    init();
    int O,S,T;
    for (int i=0; i<M; i++) {
        cin >> O >> S >> T;
        if (S > T) swap(S, T);
        if (O == 0) update(1, 1, N, S, T);
        else cout << query(1, 1, N, S, T) << '\n';
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