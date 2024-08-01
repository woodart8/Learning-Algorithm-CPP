#include <iostream>
#include <algorithm>

using namespace std;

enum Direction {
    N,  //북
    NW, //북서
    W,  //서
    SW, //남서
    S,  //남
    SE, //남동
    E,  //동
    NE  //북동
};

struct Unit{
    int num;
    int x;
    int y;
    Direction dir;
};

Unit shark = {0,0,0,N};
Unit map[4][4];
int point = 0;
int ans = 0;

const int directionOffsets[8][2] = {
    {-1, 0},  // N
    {-1, -1},  // NW
    {0, -1},   // W
    {1, -1},   // SW
    {1, 0},   // S
    {1, 1},  // SE
    {0, 1},  // E
    {-1, 1}  // NE
};

pair<int,int> nextLocation(Direction dir, int x, int y) {
    int dx = directionOffsets[dir][0];
    int dy = directionOffsets[dir][1];
    return {x + dx, y + dy};
}

void swapFish(Unit &f1, Unit &f2) {
    swap(map[f1.x][f1.y],map[f2.x][f2.y]);
    swap(f1.x, f2.x);
    swap(f1.y, f2.y);
}

bool moveFish(Unit &fish) {
    auto next = nextLocation(fish.dir, fish.x, fish.y);
    int nx = next.first;
    int ny = next.second;
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == shark.x && ny == shark.y)) {
        return false;
    }
    swapFish(fish, map[nx][ny]);
    return true;
}

void eatFish(Unit& fish) {
    shark.dir = fish.dir;
    point += fish.num;
    fish.num = -1;
    fish.dir = N;
}

bool moveShark() {
    auto next= nextLocation(shark.dir,shark.x,shark.y);
    int nx = next.first;
    int ny = next.second;
    if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) return false;
    shark.x = nx;
    shark.y = ny;
    return true;
}

Direction intToDir(int value) {
    return static_cast<Direction>(value % 8);
}

void findAndMoveFish(int num) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(map[i][j].num == num) {
                Unit &fish = map[i][j];
                do {
                    if (moveFish(fish)) return;
                    map[i][j].dir = intToDir(static_cast<int>(fish.dir) + 1);
                } while (true);
            }
        }
    }
}

void fishTurn() {
    for(int num = 1; num <= 16; num++) {
        findAndMoveFish(num);
    }
}

void backtracking() {
    fishTurn();
    Unit copyMap[4][4];
    copy(&map[0][0], &map[0][0] + 16, &copyMap[0][0]);
    while(moveShark()) {
        Unit copyShark = shark;
        Unit &fish = map[shark.x][shark.y];
        if(fish.num == -1) continue;
        eatFish(fish);
        backtracking();
        shark = copyShark;
        copy(&copyMap[0][0], &copyMap[0][0] + 16, &map[0][0]);
        point -= fish.num;
    }
    ans = max(ans,point);
}

int main() {
    int num, dir;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cin >> num >> dir;
            map[i][j] = {num, i, j, intToDir(dir-1)};
        }
    }
    eatFish(map[0][0]);
    backtracking();
    cout << ans << '\n';
    return 0;
}