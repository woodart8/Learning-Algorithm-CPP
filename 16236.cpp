#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

#define endl '\n'

// 이동 방법
// 1. 아기상어보다 큰 물고기 있는 칸은 못지나감
// 2. 크기가 같으면 먹지는 못하지만 지나갈 수는 있음
// 3. 작으면 먹음
// 4. 먹을 수 있는 물고기가 여러마리이면 거리가 가장 가까운 물고기를 먹으러감
// 5. 1마리이면 그 물고기를 먹으러 감
// 6. 먹을 수 있는 물고기가 없으면 엄마 찾으러감
// 7. 먹는 거는 대각선 왼쪽이 우선임

// 자기 크기만큼의 물고기를 먹으면 상어 크기 1 증가

struct Shark {
    int x,y;
    int size;
    int exp;
};

struct Fish {
    int x,y;
    int dist;
};

int N;
int map[21][21];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int d[21][21];
Shark baby;

void Init() {
    baby.size = 2;
    baby.exp = 0;

    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9) {
                baby.x = i;
                baby.y = j;
            }
        }
    }
}

Fish FindFish() {
    memset(d, 0, sizeof(d));
    queue<Fish> q;
    q.push({baby.x, baby.y,0});

    int minDist = 1e9;
    while(!q.empty()) {
        int dist = q.front().dist;
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] > baby.size) continue;
            if(baby.x == nx && baby.y == ny) continue;
            if(d[nx][ny] != 0) continue;
            d[nx][ny] = dist+1;
            if(map[nx][ny] == 0 || map[nx][ny] == baby.size) {
                q.push({nx,ny,dist+1});
            }
            else {
                d[nx][ny] *= -1;
                minDist = min(minDist, dist+1);
            }
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(d[i][j] == -1*minDist) return {i,j,minDist};
        }
    }
    return {0,0,0};
}

int Solve() {
    int time = 0;
    Fish target;
    do {
        target = FindFish();
        if(target.dist > 0) {
            map[baby.x][baby.y] = 0;
            baby.x = target.x;
            baby.y = target.y;
            baby.exp++;
            if(baby.exp == baby.size) {
                baby.size++;
                baby.exp = 0;
            }
            map[baby.x][baby.y] = 9;
            time += target.dist;
        }
    } while(target.dist > 0);

    return time;
}

int main() {
    Init();
    printf("%d\n",Solve());
    return 0;
}


