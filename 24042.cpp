#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 0x7fffffffffffffffLL

int N,M;
vector<pair<int, int>> v[100001];
long long dist[100001];

void dijkstra(int start) {
    priority_queue<pair<long long,int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        long long cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue; 

        for (pair<int,int>& p : v[cur]) {
            int next = p.first;
            long long nc = p.second;

            if (cost > nc) {
                nc += M * ((cost - nc) / M + 1);
            }

            if (dist[next] > nc) {
                dist[next] = nc;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }

    for (int i=1; i<=N; i++) {
        dist[i] = INF;
    }

    dijkstra(1);

    cout << dist[N] << '\n';
    return 0;
}