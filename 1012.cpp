#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 50
#define endl '\n'
int T; //테스트 케이스
int M,N,K; // 가로, 세로, 배추개수
int map[MAX][MAX]; // 지도
bool visited[MAX][MAX]; //방문 여부

int dx[4] = {-1,1,0,0}; 
int dy[4] = {0,0,-1,1};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[nx][ny] || map[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
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
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}