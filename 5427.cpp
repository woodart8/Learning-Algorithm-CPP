#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int T;
int w,h;
char map[1000][1000];
int visited[1000][1000];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int ans;
queue<pair<int,int>> fire;

void spreadFire(int x, int y) {
    fire.pop();
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= w || ny >= h || map[nx][ny] == '#' || map[nx][ny] == '*') continue;
        map[nx][ny] = '*';
        fire.push({nx,ny});
    }
}

int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 0;
    int bef = -1;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if(cx <= 0 || cy <= 0 || cx >= w-1 || cy >= h-1) return visited[cx][cy] + 1;
        if(visited[cx][cy] != bef) {
            bef = visited[cx][cy];
            int size = fire.size();
            for(int i=0; i<size; i++) {
                spreadFire(fire.front().first, fire.front().second);
            }
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(map[nx][ny] == '#' || map[nx][ny] == '*' || visited[nx][ny] != -1) continue;
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({nx,ny});
        }
    }
    return -1;
}

int main() {
    cin >> T;
    while(T--) {
        memset(visited, -1, sizeof(visited));
        while(!fire.empty()) fire.pop();
        int startX = 0;
        int startY = 0;
        cin >> w >> h;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> map[j][i];
                if(map[j][i] == '@') {
                    startX = j; 
                    startY = i;
                }
                else if(map[j][i] == '*') fire.push({j,i});
            }
        }
        ans = bfs(startX, startY);
        if(ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    return 0;
}