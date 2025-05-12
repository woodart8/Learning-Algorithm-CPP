#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200001; // n + m 최대
int segTree[MAX * 4];   // 세그먼트 트리
int position[MAX];      // 영화 번호 -> 현재 위치
int n, m;

// 세그먼트 트리 갱신: idx 위치에 diff(1 or -1) 반영
void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end) return;
    segTree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

// 세그먼트 트리 구간합: [l, r]
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return segTree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) +
           query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m;

        // 초기화
        fill(segTree, segTree + MAX * 4, 0);

        for (int i = 1; i <= n; ++i) {
            position[i] = m + i; // 초기 위치: m+1 ~ m+n
            update(1, 1, n + m, position[i], 1); // 해당 위치에 영화 추가
        }

        int top = m; // 맨 위에 올릴 다음 위치

        for (int i = 0; i < m; ++i) {
            int movie;
            cin >> movie;

            int pos = position[movie];
            // 위에 있는 영화 수 = pos보다 왼쪽(작은 인덱스) 합
            int above = query(1, 1, n + m, 1, pos - 1);
            cout << above << '\n';

            // 영화 위치 갱신
            update(1, 1, n + m, pos, -1);       // 기존 위치에서 제거
            position[movie] = top--;            // 새 위치 지정
            update(1, 1, n + m, position[movie], 1); // 새 위치에 추가
        }
    }

    return 0;
}