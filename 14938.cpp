#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int N, M, R; // N : 지역의 개수, M : 예은이의 수색범위, R : 길의 개수
vector<int> item; // 각 구역에 있는 아이템의 수
vector<pair<int,int>> graph[101]; // {idx, cost}
int dist[101]; // 각 구역으로 가는 최소 거리

// 다익스트라 알고리즘
int dijkstra(int start) {
    fill(&dist[0], &dist[100], INF); // dist 배열 INF로 초기화

    // {-cost, idx}, -cost인 이유는 pq는 기본적으로 큰 숫자 우선이기 때문에 거리가 가까운 구역을 top으로 보내기 위함
    priority_queue<pair<int, int>> pq; 
    pq.push({0, start}); // 출발지는 거리가 0
    dist[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second; // 현재 구역
        int cost = -pq.top().first; // cur까지의 거리 정보
        pq.pop();

        if (dist[cur] < cost) continue; // start -> cur에서 이미 cost보다 짧은 경로가 존재할 경우 continue

        // 인접 구역 검사
        for (pair<int, int> p : graph[cur]) {
            int next = p.first;
            int ncost = p.second;

            // 더 짧은 경로 찾기
            if (dist[next] > dist[cur] + ncost) {
                dist[next] = dist[cur] + ncost;
                pq.push({-ncost, next});
            }
        }
    }

    // 수색범위 내에 있는 구역만 더하기
    int ret = 0;
    for (int i=1; i<=N; i++) {
        if (dist[i] <= M) ret += item[i]; 
    }
    return ret;
}

void input() {
    cin >> N >> M >> R;
    item.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> item[i];
    }
    for (int i=1; i<=R; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }
}

void solve() {
    int answer = 0;
    for (int i=1; i<=N; i++) {
        answer = max(answer, dijkstra(i));
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}