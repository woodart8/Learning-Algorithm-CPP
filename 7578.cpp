#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> num;
vector<int> pos;
vector<long long> tree;

void input() {
    cin >> N;
    num.resize(N);
    pos.resize(1000001);
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }

    int key;
    for (int i=0; i<N; i++) {
        cin >> key;
        pos[key] = i;
    }
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    long long lsum = query(node*2, start, (start+end)/2, left, right);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, idx, diff);
        update(node*2+1, (start+end)/2+1, end, idx, diff);
    }
}

void solve() {
    tree.resize(4*N+1);
    long long sum = 0;
    for (int i=0; i<N; i++) {
        int key = num[i];
        sum += query(1, 0, N-1, pos[key]+1, N-1);
        update(1, 0, N-1, pos[key], 1);
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}