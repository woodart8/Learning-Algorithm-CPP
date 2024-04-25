#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAX 50
#define endl '\n'
int T;
int M,N,K;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[nx][ny] || map[nx][ny]==0) continue;
        dfs(nx,ny);
    }
}

void dfs_stack(int x, int y) {
    stack<pair<int,int>> S;
    S.push({x,y});
    visited[x][y] = true;
    while(!S.empty()) {
        int curx = S.top().first;
        int cury = S.top().second;
        S.pop();
        for(int i=0; i<4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[nx][ny] || map[nx][ny]==0) continue;
            visited[nx][ny] = true;
            S.push({nx,ny});
        }
    }
    return;
}

int main() {
    cin >> T;
    while(T--) {
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> K;
        for(int i=0; i<K; i++) {
            int x,y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        int cnt = 0;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(!visited[i][j] && map[i][j] == 1) {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}