#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 100
#define endl '\n'

int N;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
            if(map[x][y] != map[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) continue;
        if(map[x][y] != map[nx][ny]) continue;
        dfs(nx,ny);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                bfs(i,j);
                // dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << ' ';

    cnt = 0;
    memset(visited, false, sizeof(visited));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                bfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}