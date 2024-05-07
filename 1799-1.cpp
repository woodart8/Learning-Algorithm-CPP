#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
bool map[11][11];
bool va[21];
bool vb[21];
int ans[2];


void BT(int x, int y, int n, int color) {
    if(x > N) {
        ans[color] = max(ans[color], n);
        return;
    }

    int nx = 0;
    int ny = 0;
    if(N % 2 == 1) {
        nx = (y==N || y==N-1) ? x+1 : x;
        ny = y==N ? 2 : y+2;
        if(ny > N) ny = 1;
    }
    else {
        nx = (y==N || y==N-1) ? x+1 : x;
        ny = y==N ? 1 : y+2;
        if(ny > N) ny = 2;
    } 

    if(map[x][y] && !va[N-x+y] && !vb[x+y]) {
        va[N-x+y] = true;
        vb[x+y] = true;
        BT(nx, ny, n+1, color);
        va[N-x+y] = false;
        vb[x+y] = false;
    }
    BT(nx, ny, n, color);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }

    BT(1,1,0,0);
    BT(1,2,0,1);
    cout << ans[0]+ans[1] << endl;
    return 0;
}