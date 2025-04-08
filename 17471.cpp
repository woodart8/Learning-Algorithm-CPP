#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int popl[11];
int parent[11];
bool graph[11][11];
int total = 0;
int answer = 1e9;

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionNode(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) parent[b] = a;
}

bool isConnected(const vector<int>& group) {
    if (group.empty()) return false;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i : group) {
        for (int j : group) {
            if (graph[i][j]) {
                unionNode(i, j);
            }
        }
    }

    int root = findParent(group[0]);
    for (int i : group) {
        if (findParent(i) != root) return false;
    }

    return true;
}

void bt(int last, vector<int> a) {
    // a 그룹이 선거구를 다 가져가는 것 방지
    if ((int)a.size() == N) return;

    vector<bool> isGroupA(N + 1, false);
    for (int x : a) isGroupA[x] = true;

    vector<int> b;
    for (int i = 1; i <= N; i++) {
        if (!isGroupA[i]) b.push_back(i);
    }

    // 각 그룹이 실제로 연결되었는지 검사
    if (isConnected(a) && isConnected(b)) {
        int poplA = 0;
        for (int x : a) poplA += popl[x];
        answer = min(answer, abs(2 * poplA - total));
    }

    for (int i = last + 1; i <= N; i++) {
        a.push_back(i);
        bt(i, a);
        a.pop_back();
    }
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> popl[i];
        total += popl[i];
    }

    for (int i = 1; i <= N; i++) {
        int neighbor;
        cin >> neighbor;
        for (int j = 0; j < neighbor; j++) {
            int num;
            cin >> num;
            graph[i][num] = true;
            graph[num][i] = true;
        }
    }
}

void solve() {
    for (int i = 1; i <= N / 2; i++) {
        vector<int> a;
        a.push_back(i);
        bt(i, a);
    }

    if (answer == 1e9) answer = -1;
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}