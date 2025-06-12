#include <iostream>

using namespace std;

int N, M;
int map[504][504];

// I모양 블록
int calcI(int x, int y) {
    int ret = 0;

    int sum = 0;
    for (int i=0; i<4; i++)
        sum += map[x][y+i];
    ret = max(ret, sum);

    sum = 0;
    for (int i=0; i<4; i++)
        sum += map[x+i][y];
    ret = max(ret, sum);

    return ret;
}

// O모양 블록
int calcO(int x, int y) {
    return map[x][y] + map[x][y+1] + map[x+1][y] + map[x+1][y+1];
}

// S모양 블록
int calcS(int x, int y) {
    int ret = 0;
    ret = max(ret, map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+2][y+1]);
    ret = max(ret, map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x+1][y+2]);

    if (x > 0) ret = max(ret, map[x][y] + map[x][y+1] + map[x-1][y+1] + map[x-1][y+2]);
    if (y > 0) ret = max(ret, map[x][y] + map[x+1][y] + map[x+1][y-1] + map[x+2][y-1]);

    return ret;
}

// L모양 블록
int calcL(int x, int y) {
    int ret = 0;
    ret = max(ret, map[x][y] + map[x+1][y] + map[x+2][y] + map[x+2][y+1]);
    ret = max(ret, map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x+2][y+1]);
    ret = max(ret, map[x][y] + map[x][y+1] + map[x][y+2] + map[x+1][y+2]);
    ret = max(ret, map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+1][y+2]);

    if (x > 0) {
        ret = max(ret, map[x][y] + map[x][y+1] + map[x][y+2] + map[x-1][y+2]);
        ret = max(ret, map[x][y] + map[x-1][y] + map[x-1][y+1] + map[x-1][y+2]);
    }
    if (y > 0) {
        ret = max(ret, map[x][y] + map[x+1][y] + map[x+2][y] + map[x+2][y-1]);
        ret = max(ret, map[x][y] + map[x][y-1] + map[x+1][y-1] + map[x+2][y-1]);
    }

    return ret;
}

// T모양 블록
int calcT(int x, int y) {
    int ret = 0;
    ret = max(ret, map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+2][y]);
    ret = max(ret, map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x][y+2]);

    if (x > 0) ret = max(ret, map[x][y] + map[x][y+1] + map[x-1][y+1] + map[x][y+2]);
    if (y > 0) ret = max(ret, map[x][y] + map[x+1][y] + map[x+1][y-1] + map[x+2][y]);

    return ret;
}

int calcSum(int x, int y) {
    int ret = 0;

    ret = max(ret, calcI(x, y));
    ret = max(ret, calcO(x, y));
    ret = max(ret, calcS(x, y));
    ret = max(ret, calcL(x, y));
    ret = max(ret, calcT(x, y));

    return ret;
}

void input() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
}

void solve() {
    int answer = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            answer = max(answer, calcSum(i,j));
        }
    }
    cout << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}