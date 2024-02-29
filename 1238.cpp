#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9

int n, m , x;

vector<pair<int, int>> graph[1001];

void dijkstra(int start, int *d) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    fill(d,d+1001, INF);
    d[start] = 0;

    while(!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist)
            continue;
        
        for(int i=0; i<graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main() {
    int d1[1001], d2[1001];
    int max = 0;
    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    dijkstra(x, d1);
    
    for(int i=1; i<=n; i++) {
        dijkstra(i, d2);
        d1[i] += d2[x];
        if(d1[i] > max) {
            max = d1[i];
        }
    }

    cout << max;
    return 0;
}