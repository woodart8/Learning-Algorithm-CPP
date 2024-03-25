#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int cheese;
int N,M;

void checkAir(int x, int y, int count) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    map[x][y] = count;
    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = now_x+dx[i];
            int ny = now_y+dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if(map[nx][ny]==1 || visited[nx][ny]) continue;
            map[nx][ny] = count;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

void init() {
    memset(visited,false,sizeof(visited));
    int count = 2;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(map[i][j]==0 && !visited[i][j]){
                checkAir(i,j,count);
                count++;
            }
        }
    }
    memset(visited,false,sizeof(visited));
}

int bfs(int x, int y) {
    int ret = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        int count = 0;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = now_x+dx[i];
            int ny = now_y+dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny]>2 || visited[nx][ny]) continue;
            if(map[nx][ny]==2) {
                count++; 
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
        if(count>=2) {
            map[now_x][now_y] = 0;
            ret++;
        }
    }
    return ret;
}

int solve() {
    int T = 0;
    while(1){
        init();
        if(cheese==0) break;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(map[i][j]==1 && !visited[i][j])
                    cheese -= bfs(i,j);
            }
        }
        T++;
    }
    return T;
}

int main() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> map[i][j];
            if(map[i][j]==1) cheese++;
        }
    }

    cout << solve() << endl;
    return 0;
}