#include <iostream>
#include <vector>
#include <queue>

#define INF 1e15

using namespace std;

int n, m, k;
long long ans = INF;
long long d[10001][21];
vector<vector<pair<int, int>>> graph;

void dijkstra(int start) {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            d[i][j] = INF;
        }
    }
    priority_queue<pair<pair<long long,int>, int>> pq;
    pq.push({{0, start}, 0});
    d[start][0] = 0;

    while(!pq.empty()) {
        long long dist = -pq.top().first.first;
        int now = pq.top().first.second;
        int cnt = pq.top().second;
        pq.pop();

        if(d[now][cnt] < dist) continue;

        for(int i=0; i<graph[now].size(); i++) {
            long long cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first][cnt]) {
                d[graph[now][i].first][cnt] = cost;
                pq.push({{-cost, graph[now][i].first}, cnt});
            }
            if(dist < d[graph[now][i].first][cnt+1] && cnt+1 <= k) {
                d[graph[now][i].first][cnt+1] = dist;
                pq.push({{-dist, graph[now][i].first}, cnt+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    graph.resize(n+1);
    
    int a, b, c;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dijkstra(1);

    for(int i=0; i<=k; i++) ans = min(ans, d[n][i]);
    cout << ans << endl; 
    return 0;
}