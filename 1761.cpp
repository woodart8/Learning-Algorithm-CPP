#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define TREE_HEIGHT 16

int N, M;
vector<pair<int, int>> v[40001];
int depth[40001];
int parent[40001][TREE_HEIGHT];
int dist[40001][TREE_HEIGHT];

void input() {
    cin >> N;

    for (int i=0; i<N-1; i++) {
        int s,e,d;
        cin >> s >> e >> d;
        v[s].push_back({e,d});
        v[e].push_back({s,d});
    }
}

void findParent(int par, int now, int dep, int cost){
    depth[now] = dep;
    parent[now][0] = par;
    dist[now][0] = cost;

    for(int i=0; i<v[now].size(); ++i){
        if(v[now][i].first != par)
            findParent(now, v[now][i].first, dep+1,v[now][i].second);
    } 
    return;
}

void fillRest() {
    for(int k=1; k<TREE_HEIGHT; k++){
        for(int i=2; i<=N; i++){
            if(parent[i][k-1] != 0){
                parent[i][k] = parent[parent[i][k-1]][k-1];
                dist[i][k] = dist[i][k-1] + dist[parent[i][k-1]][k-1];
            }
        }
    }
}

int getDist(int a, int b) {
    int sum = 0;
    if (depth[a] != depth[b]) {
        if (depth[a] < depth[b]) swap(a,b);

        int diff = depth[a] - depth[b];
        for (int i=0; diff>0; i++) {
            if (diff % 2) {
                sum += dist[a][i];
                a = parent[a][i];
            } 
            diff >>= 1;
        }
    }

    if (a != b) {
        for (int k=TREE_HEIGHT-1; k>=0; k--) {
            if (parent[a][k] != 0 && parent[a][k] != parent[b][k]) {
                sum += (dist[a][k] + dist[b][k]);
                a = parent[a][k];
                b = parent[b][k];
            }
        }

        sum += dist[a][0] + dist[b][0];
    } 

    return sum;
}

void init() {
    memset(parent, 0 , sizeof(parent));
    memset(dist, 0, sizeof(dist));
    findParent(0, 1, 0, 0);
    fillRest();
}

void solve() {
    init();

    cin >> M;

    for (int i=0; i<M; i++) {
        int s,e;
        cin >> s >> e;
        cout << getDist(s,e) << '\n';
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