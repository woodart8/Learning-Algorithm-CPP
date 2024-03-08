#include <iostream>

using namespace std;

char map[5][5];
bool visited[5][5] = {false};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0 , 1};
int R,C,K;
int ans;

void dfs(int cost, int x, int y) {
    if(cost == K) {
        if(x == C-1 && y == 0)
            ans++; 
        return;
    }
    for(int i=0; i<4; i++) {
        if(x+dx[i]>=0 && x+dx[i]<C && y+dy[i]>=0 && y+dy[i]<R) {
            if(!visited[y+dy[i]][x+dx[i]]) {
                visited[y+dy[i]][x+dx[i]] = true;
                dfs(cost+1, x+dx[i], y+dy[i]);
                visited[y+dy[i]][x+dx[i]] = false;
            }
        }
    }
}

int main() {
    cin >> R >> C >> K;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'T') visited[i][j] = true;
        }
    }

    visited[R-1][0] = true;
    dfs(1, 0, R-1);
    cout << ans << endl;
    return 0;
}