#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 101

struct Curve {
    int x,y,d,g;
    vector<int> dir; //그리는데 필요한 방향 배열
};

int N;
bool map[MAX][MAX]; //드래곤 커브가 해당 좌표를 지나가는 지 확인하는 배열
int nxt[4] = {1,2,3,0}; //시계방향으로 돌렸을 때 다음 방향
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

vector<Curve> dragon;

void Draw() {
    for(int i=0; i<dragon.size(); i++) {
        for(int j=1; j<=dragon[i].g; j++) {
            int sz = dragon[i].dir.size();
            for(int k=sz-1; k>=0; k--) {
                dragon[i].dir.push_back(nxt[dragon[i].dir[k]]);
            }
        }
    }

    for(int i=0; i<dragon.size(); i++) {
        int ny = dragon[i].y;
        int nx = dragon[i].x;
        map[ny][nx] = true;
        for(int j=0; j<dragon[i].dir.size(); j++) {
            ny += dy[dragon[i].dir[j]];
            nx += dx[dragon[i].dir[j]];
            if(ny < 0 || nx < 0 || ny >= MAX || nx >= MAX || map[ny][nx]) continue;
            map[ny][nx] = true;
        }
    }
}

int Solve() {
    int ret = 0;
    for(int i=0; i<MAX-1; i++) {
        for(int j=0; j<MAX-1; j++) {
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) {
                ret++;
            }
        }
    }

    return ret;
}

int main() {
    cin >> N;
    for(int i=1; i<=N ;i++) {
        Curve c;
        cin >> c.x >> c.y >> c.d >> c.g;
        c.dir.push_back(c.d);
        dragon.push_back(c);
    }

    Draw();
    cout << Solve() << endl;
    return 0;
}