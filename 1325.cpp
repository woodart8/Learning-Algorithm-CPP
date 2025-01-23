#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> v[10001];
bool visited[10001];
int mem[10001];

void input() {
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
}

int dfs(int cur, int cnt) {
    visited[cur] = true;

    for (int i=0; i<v[cur].size(); i++) {
        int next = v[cur][i];
        if (visited[next]) continue;
        cnt = dfs(next, cnt+1);
    }

    return cnt;
}

void solve() {
    int maximum = 0;
    for (int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(visited));
        mem[i] = dfs(i, 1);
        maximum = max(maximum, mem[i]);
    }

    for (int i=1; i<=N; i++) {
        if (maximum == mem[i]) {
            cout << i << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}