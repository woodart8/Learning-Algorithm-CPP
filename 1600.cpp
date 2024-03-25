#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 200

int K, W, H;
int map[MAX][MAX];
bool d[MAX][MAX][31];
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};
int ddx[] = {0, 0, -1, 1};
int ddy[] = {1, -1, 0, 0};

void bfs(int x, int y) {
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{x,y}});
    while(!q.empty()) {
        int step = q.front().first.first;
        int k = q.front().first.second;
        int now_x = q.front().second.first;
        int now_y = q.front().second.second;
        q.pop();
        
        if(now_x == H-1 && now_y == W-1) {
            cout << step << endl;
            return;
        }
        if(k < K) {
            for(int i=0; i<8; i++) {
                int nx = now_x + dx[i];
                int ny = now_y + dy[i];
                if(nx < 0 || ny < 0 || nx >= H || ny >= W || map[nx][ny]==1 || d[nx][ny][k+1]) continue;
                d[nx][ny][k+1] = true;
                q.push({{step+1,k+1},{nx,ny}});
            }
        }
        for(int i=0; i<4; i++) {
            int nx = now_x + ddx[i];
            int ny = now_y + ddy[i];
            if(nx < 0 || ny < 0 || nx >= H || ny >= W || map[nx][ny]==1 || d[nx][ny][k]) continue;
            d[nx][ny][k] = true;
            q.push({{step+1,k},{nx,ny}});
        }
    }
    cout << -1 << endl;
}

int main() {
    cin >> K >> W >> H;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> map[i][j];
        }
    }
    bfs(0,0);
    return 0;
}