#include <iostream>
#include <vector>
using namespace std;

int N,M,x,y,d;
int map[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int turn[] = {3, 0, 1 ,2};
int back[] = {2, 3, 0, 1};
int ans;

bool check4(int x, int y) {
    bool ret = false;
    for(int i=0; i<4; i++) {
        int next_x = x+dx[i];
        int next_y = y+dy[i];
        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && map[next_x][next_y] == 0) ret = true;
    }
    return ret;
}

void clean(int tx, int ty) {
    if(map[tx][ty] == 0) {
        map[tx][ty] = 2;
        ans++;
    }
    if(check4(tx,ty)) {
        d = turn[d];
        int next_x = tx + dx[d];
        int next_y = ty + dy[d];
        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && map[next_x][next_y] == 0) {
            clean(next_x,next_y);
        }
        else if(map[next_x][next_y] != 0) {
            clean(tx,ty);
        }
    }
    else {
        int next_x = tx + dx[back[d]];
        int next_y = ty + dy[back[d]];
        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && map[next_x][next_y] != 1) {
            clean(next_x,next_y);
        }
        else {
            return;
        }
    }
}

int simulation() {
    clean(x,y);
    return ans;
}
int main() {
    cin >> N >> M >> x >> y >> d;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }

    cout << simulation();
    return 0;
}