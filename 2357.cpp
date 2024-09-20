#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTreeMinMax {
    vector<int> minTree;  // 최솟값 세그먼트 트리
    vector<int> maxTree;  // 최댓값 세그먼트 트리
    int n;

public:
    // 생성자: 배열을 받아서 세그먼트 트리 빌드
    SegmentTreeMinMax(const vector<int>& data) {
        n = data.size();
        minTree.resize(4 * n);
        maxTree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    // 세그먼트 트리 빌드 (최솟값과 최댓값 트리를 동시에 생성)
    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            minTree[node] = data[start];  // 리프 노드에 데이터 저장
            maxTree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            // 자식 노드들의 최솟값, 최댓값을 부모 노드에 저장
            minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
            maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
        }
    }

    // 구간 최솟값 쿼리
    int queryMin(int L, int R) {
        return queryMin(0, 0, n - 1, L, R);
    }

    // 구간 최솟값을 구하는 재귀 함수
    int queryMin(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INT_MAX;  // 구간이 겹치지 않으면 최댓값 반환
        }
        if (L <= start && end <= R) {
            return minTree[node];  // 구간이 완전히 포함될 때
        }
        int mid = (start + end) / 2;
        int leftMin = queryMin(2 * node + 1, start, mid, L, R);
        int rightMin = queryMin(2 * node + 2, mid + 1, end, L, R);
        return min(leftMin, rightMin);  // 왼쪽과 오른쪽 구간의 최솟값 반환
    }

    // 구간 최댓값 쿼리
    int queryMax(int L, int R) {
        return queryMax(0, 0, n - 1, L, R);
    }

    // 구간 최댓값을 구하는 재귀 함수
    int queryMax(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INT_MIN;  // 구간이 겹치지 않으면 최솟값 반환
        }
        if (L <= start && end <= R) {
            return maxTree[node];  // 구간이 완전히 포함될 때
        }
        int mid = (start + end) / 2;
        int leftMax = queryMax(2 * node + 1, start, mid, L, R);
        int rightMax = queryMax(2 * node + 2, mid + 1, end, L, R);
        return max(leftMax, rightMax);  // 왼쪽과 오른쪽 구간의 최댓값 반환
    }

    // 특정 값을 업데이트하는 함수
    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    // 재귀적으로 세그먼트 트리를 업데이트
    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            minTree[node] = value;
            maxTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            // 자식 노드들의 최솟값, 최댓값을 부모 노드에 반영
            minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
            maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
        }
    }
};


int N,M;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    v.resize(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    SegmentTreeMinMax segTree(v);

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        cout << segTree.queryMin(a-1, b-1) << " " << segTree.queryMax(a-1, b-1) << "\n";
    }

    return 0;
}