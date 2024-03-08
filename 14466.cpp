#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,K,R;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pair<int,int>> loc;
int map[101][101];
bool visited[101][101];
vector<pair<int,int>> road[101][101];

int bfs(int x, int y) {
    int count = 0;
    memset(visited, false, sizeof(visited));
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            bool check = false;
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if(next_x < 1 || next_y < 1 || next_x > N || next_y > N || visited[next_x][next_y]) continue;
            for(int i=0; i<road[now_x][now_y].size(); i++) {
                if(road[now_x][now_y][i].first == next_x && road[now_x][now_y][i].second == next_y)
                    check = true;
            }
            if(check) continue;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(!visited[i][j] && map[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}


int main() {
    cin >> N >> K >> R;
    for(int i=0; i<R; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        road[x1][y1].push_back({x2, y2});
        road[x2][y2].push_back({x1, y1});
    }
    for(int i=0; i<K; i++) {
        int x, y;
        cin >> x >> y;
        loc.push_back({x,y});
        map[x][y] = 1;
    }

    int ans = 0;
    for(int i=0; i<loc.size(); i++) {
        ans += bfs(loc[i].first, loc[i].second);
    }
    cout << ans/2 << endl;
    return 0;
}