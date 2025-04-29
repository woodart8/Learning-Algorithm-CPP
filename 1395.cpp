#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> tree; // 세그멘트 트리
vector<int> lazy; // 느린 전파 0 : 변경사항 없음, 1 : 변경됨

void input() {
    cin >> N >> M;
}

// 트리 크기 지정
void init() {
    tree.resize(4*N);
    lazy.resize(4*N);
}

// 반전 내역 반영
void update_lazy(int node, int start, int end) {
    // 반전되어야하는 경우
    if (lazy[node] != 0) {
        tree[node] = -1 * tree[node] + (end-start+1); // 스위치 반전
        if (start != end) {
            // 자식 노드에 반전 내역 기록
            lazy[node*2] ^= 1;
            lazy[node*2+1] ^= 1;
        }
        lazy[node] = 0;
    }
}

// [left, right] 구간에 있는 스위치 반전
void update(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end); // 이전 반전 내역 반영

    // 현재 구간이 범위 밖이면 return
    if(left > end || right < start) return;

    // 현재 구간이 [left, right] 내에 속한 경우
    if (left <= start && end <= right) {
        tree[node] = -1 * tree[node] + (end-start+1); // 스위치 반전
        // 자식 노드에 반전 내역 기록
        if (start != end) {
            lazy[node*2] ^= 1;
            lazy[node*2+1] ^= 1;
        }
        return;
    }

    // 현재 구간이 [left, right]에 걸친 경우
    update(node*2, start, (start+end)/2, left, right);
    update(node*2+1, (start+end)/2+1, end, left, right);
    tree[node] = tree[node*2] + tree[node*2+1];
}

// [left, right] 구간에 켜져있는 스위치 숫자 반환
int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end); // 이전 반전 내역 반영

    // 현재 구간이 범위 밖이면 0 return
    if (left > end || right < start) return 0;

    // 현재 구간이 [left, right] 내에 속한 경우
    if (left <= start && end <= right) return tree[node];

    // 현재 구간이 [left, right]에 걸친 경우
    int lsum = query(node*2, start, (start+end)/2, left, right);
    int rsum = query(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

void solve() {
    init();
    int O,S,T;
    for (int i=0; i<M; i++) {
        cin >> O >> S >> T;
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