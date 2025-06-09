#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1E9

struct Passenger {
    int idx;
    int startX, startY;
    int targetX, targetY;
};

struct Taxi {
    int x, y;
    int fuel;
};

int N, M;
bool map[21][21]; // 벽이면 true
bool arrived[400]; // 도착 여부
int dist[21][21]; // 최단 거리
Taxi taxi;
vector<Passenger> v;

void bfs(int initX, int initY) {
    fill(&dist[0][0], &dist[20][21], INF);
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    q.push({initX, initY});
    dist[initX][initY] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (dist[nx][ny] != INF || map[nx][ny]) continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}

Passenger* findPassenger() {
    Passenger* target = nullptr;
    int minDist = INF;
    for (Passenger& p : v) {
        if (arrived[p.idx]) continue;
        int d = dist[p.startX][p.startY];
        if (d == INF) continue; // 갈 수 없는 경우는 제외

        if (d < minDist) {
            minDist = d;
            target = &p;
        } else if (d == minDist) {
            if (p.startX < target->startX || (p.startX == target->startX && p.startY < target->startY)) {
                target = &p;
            }
        }
    }
    return target;
}

void input() {
    cin >> N >> M >> taxi.fuel;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = (tmp == 1);
        }
    }
    cin >> taxi.x >> taxi.y;
    for (int i = 0; i < M; i++) {
        Passenger p;
        p.idx = i;
        cin >> p.startX >> p.startY >> p.targetX >> p.targetY;
        v.push_back(p);
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        bfs(taxi.x, taxi.y);

        Passenger* p = findPassenger();
        if (p == nullptr) {
            cout << -1 << '\n';
            return;
        }

        int toPassenger = dist[p->startX][p->startY];
        if (taxi.fuel < toPassenger) {
            cout << -1 << '\n';
            return;
        }

        // 손님에게 이동
        taxi.fuel -= toPassenger;
        taxi.x = p->startX;
        taxi.y = p->startY;

        // 목적지까지 거리 계산
        bfs(taxi.x, taxi.y);
        int toDest = dist[p->targetX][p->targetY];
        if (toDest == INF || taxi.fuel < toDest) {
            cout << -1 << '\n';
            return;
        }

        // 목적지로 이동
        taxi.fuel += toDest;
        taxi.x = p->targetX;
        taxi.y = p->targetY;
        arrived[p->idx] = true;
    }

    cout << taxi.fuel << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}
