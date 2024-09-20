#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define MOD 1000000007

class SegmentTree {

    private:
        vector<long long> tree;
        int n;

    public:
        SegmentTree(const vector<long long>& data) {
            n = data.size();
            tree.resize(4 * n);
            build(data, 0, 0, n-1);
        }

        void build(const vector<long long>& data, int node, int start, int end) {
            if (start == end) {
                tree[node] = data[start];
            } else {
                int mid = (start + end) / 2;
                build(data, 2 * node + 1, start, mid);
                build(data, 2 * node + 2, mid + 1, end);
                tree[node] = tree[2 * node + 1] * tree[2 * node + 2] % MOD;
            }
        }
        
        long long query(int left, int right) {
            return query(0, 0, n-1, left, right);
        }

        long long query(int node, int start, int end, int left, int right) {
            if (right < start || end < left) return 1;
            if (left <= start && end <= right) return tree[node];
            int mid = (start + end) / 2;
            long long leftRes = query(2 * node + 1, start, mid, left, right);
            long long rightRes = query(2 * node + 2, mid + 1, end, left, right);
            return (leftRes * rightRes) % MOD;
        }

        void update(int index, long long value) {
            update(0, 0, n-1, index, value);
        }

        void update(int node, int start, int end, int index, long long value) {
            if (start == end) {
                tree[node] = value;
            } else {
                int mid = (start + end) / 2;
                if (index <= mid) update(2 * node + 1, start, mid, index, value);
                else update(2 * node + 2, mid + 1, end, index, value);
                tree[node] = tree[2 * node + 1] * tree[2 * node + 2] % MOD;
            }
        }

};

int N,M,K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    vector<long long> data(N);
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    SegmentTree st(data);

    for (int i = 0; i < M+K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) st.update(b-1, c);
        else cout << st.query(b-1, c-1) << '\n';
    }

    return 0;
}