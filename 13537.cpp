#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> tree;
vector<int> num;

// 병합 정렬
vector<int> mergeSort(const vector<int>& a, const vector<int>& b) {
    vector<int> ret;

    int i = 0, j = 0;
    while(i<a.size() && j<b.size()) {
        if (a[i] < b[j]) {
            ret.push_back(a[i++]);
        } else {
            ret.push_back(b[j++]);
        }
    }
    while (i<a.size()) {
        ret.push_back(a[i++]);
    }
    while (j<b.size()) {
        ret.push_back(b[j++]);
    }
    
    return ret;
}

// 트리 초기화
void makeTree(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(num[start]);
        return;
    }
    makeTree(node*2, start, (start+end)/2);
    makeTree(node*2+1, (start+end)/2+1, end);
    tree[node] = mergeSort(tree[node*2], tree[node*2+1]);
}

// left-right 구간에서 val보다 큰 숫자 개수 찾기
int query(int node, int start, int end, int left, int right, int val) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
    }
    int lval = query(node*2, start, (start+end)/2, left, right, val);
    int rval = query(node*2+1, (start+end)/2+1, end, left, right, val);
    return lval + rval;
}

void init() {
    cin >> N;
    num.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> num[i];
    }
    tree.resize(4*N);
    makeTree(1, 1, N);
}

void solve() {
    cin >> M;
    int a, b, c;
    for (int i=1; i<=M; i++) {
        cin >> a >> b >> c;
        cout << query(1, 1, N, a, b, c) << '\n';
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