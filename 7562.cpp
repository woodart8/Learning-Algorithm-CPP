#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 300

int T, I;
int currentX, currentY, targetX, targetY;
int arr[MAX][MAX];
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

void bfs(int x,int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    arr[x][y] = 0;
    
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 도착했으면 횟수 출력하고 return
        if(cx == targetX && cy == targetY) {
            cout << arr[cx][cy] << '\n';
            return;
        }

        for(int i=0;i<8;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 배열 범위 밖으로 나가거나 이미 방문한 적 있는 경우 continue
            if(nx < 0 || nx >= I || ny < 0 || ny >= I || arr[nx][ny] >= 0) continue;

            q.push({nx, ny});
            arr[nx][ny] = arr[cx][cy]+1;
        }
    }
}

void init() {
    memset(arr, -1, sizeof(arr));
}

void input() {
    cin >> I;
    cin >> currentX >> currentY;
    cin >> targetX >> targetY;
}

void solve() {
    // bfs는 최단 경로를 보장한다.
    bfs(currentX, currentY);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        init();
        input();
        solve();
    }

    return 0;
}