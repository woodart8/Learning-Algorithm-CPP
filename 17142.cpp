#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int map[50][50];
int visited[50][50];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<pair<int,int>> virus;
vector<pair<int,int>> active_virus;
int ans = 1e9;
int secureCnt = 0;

int spread() {
    queue<pair<int,int>> q;
    memset(visited, -1, sizeof(visited));
    for(int i=0; i<active_virus.size(); i++) {
        q.push({active_virus[i].first,active_virus[i].second});
        visited[active_virus[i].first][active_virus[i].second] = 0;
    }

    int time = 0;
    int cnt = 0;
    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
            if(map[next_x][next_y] == 1) continue;
            if(visited[next_x][next_y] == -1) {
                visited[next_x][next_y] = visited[now_x][now_y] + 1;
                if(map[next_x][next_y] == 0) {
                    time = visited[next_x][next_y];
                    cnt++;
                }
                q.push({next_x,next_y});
            }
        }
    }
    if(cnt == secureCnt) return time;
    else return 1e9;
}

void dfs(int cnt, int idx) {
    if(cnt == M)  {
        ans = min(ans, spread());
        return;
    }
    for(int i=idx; i<virus.size(); i++) {
        active_virus.push_back({virus[i].first, virus[i].second});
        dfs(cnt+1, i+1);
        active_virus.pop_back();
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push_back({i,j});
            else if(map[i][j] == 0) secureCnt++;
        }
    }
    dfs(0, 0);
    if(ans == 1e9) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}