#include <queue>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int now_x, int now_y, int num) {
    if(num > 100) {
        ans = max(ans, asdf)
        return;
    }

    for(int i=0; i<4; i++) {
        int nx= now_x + dx[i];
        int ny = now_y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || visited[nx][ny]) continue;
        dfs(nx,ny, num+asdf);
    }
}


void bfs(int now_X, int now_y) {
    queue<pair<int,int>> q;

    q.push({now_x, now_y});

    while(!q.empty()) {
        
    }
}
