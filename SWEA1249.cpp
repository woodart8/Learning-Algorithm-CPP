#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int T;
int N;
int map[101][101];
int dist[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
bool visited[101][101];

void bfs(int x, int y) {
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({0,{x,y}});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();
        if(cx == N && cy == N) break;
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(dist[nx][ny] > cost + map[nx][ny]) {
                dist[nx][ny] = cost + map[nx][ny];
                pq.push({-dist[nx][ny], {nx,ny}});
            }
        }
    }
}

int main() {
    cin >> T;
    int tc = 1;
    while(tc <= T) {
        cin >> N;

        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        fill_n(&dist[0][0], 101*101, INT32_MAX);
        dist[1][1] = 0;

        char c;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                cin >> c;
                map[i][j] = c-'0';
            }
        }

        bfs(1,1);

        cout << '#' << tc << ' ' << dist[N][N] << '\n';
        tc++;
    }
    return 0;
}