#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> popl; // 인구 수
vector<int> tree[10001]; // 인접 노드 리스트
int dp[10001][2]; // dp[i][0]은 i번 노드를 선택하지 않은 경우, dp[i][1]은 i번 노드를 선택한 경우의 최댓값
bool visited[10001]; // 방문 배열

// dfs를 통한 dp
void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0;
    dp[node][1] = popl[node];

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);
            dp[node][0] += max(dp[child][0], dp[child][1]); // 현재 노드를 선택하지 않을 경우에는 자식 노드의 선택 여부에 따라 값 결정
            dp[node][1] += dp[child][0]; // 현재 노드를 선택할 경우에는 자식 노드를 선택하지 않아야 한다.
        }
    }
}

void input() {
    cin >> N;
    popl.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> popl[i];
    }

    int a, b;
    for (int i=1; i<=N-1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void solve() {
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}