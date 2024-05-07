#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M,K;
long long v[1000001];
long long SegTree[2100000];

long long makeSegTree(int node, int start, int end) {
    if(start == end) return SegTree[node] = v[start];
    int mid = (start + end) / 2;
    return SegTree[node] = makeSegTree(node*2, start, mid) + makeSegTree(node*2+1, mid+1, end);
}

void updateSegTree(int node, int start, int end, int idx, long long diff) {
    if(idx < start || idx > end) return;
    SegTree[node] += diff;
    if(start != end) {
        int mid = (start+end)/2;
        updateSegTree(node*2, start, mid, idx, diff);
        updateSegTree(node*2+1, mid+1, end, idx, diff);
    }
}

long long sumSegTree(int node, int left, int right, int start, int end) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return SegTree[node];
    int mid = (start + end) / 2;
    return sumSegTree(node*2, left, right, start, mid) + sumSegTree(node*2+1, left, right, mid+1, end);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;

    for(int i=1; i<=N; i++) {
        cin >> v[i];
    }

    makeSegTree(1,1,N);

    long long a,b,c;
    for(int i=0; i<M+K; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            updateSegTree(1,1,N,b,c-v[b]);
            v[b] = c;
        }
        else {
            cout << sumSegTree(1,b,c,1,N) << '\n';
        }
    }
    return 0;
}