#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000001

int N;
vector<int> tree[MAX];
int dp[MAX][2];

void DFS(int now, int parent) {
    dp[now][0] = 1;
    for(auto next : tree[now]) {
        if(next == parent) continue;
        DFS(next, now);
        dp[now][0] += min(dp[next][0],dp[next][1]);
        dp[now][1] += dp[next][0];
    }
}

int Solve(int start) {
    DFS(start, 0);
    return min(dp[start][0], dp[start][1]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<N; i++) {
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << Solve(1) << '\n';

    return 0;
}