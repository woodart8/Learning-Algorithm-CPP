#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
bool map[11][11];
bool bishop[11][11];
bool check[11][11][2];
int ans[2];

bool isSafe(int leftx, int lefty, int rightx, int righty) {
    if(check[leftx][lefty][0] || check[rightx][righty][1]) return false;
    else {
        return true;
    }
}

void BT(int x, int y, int n, int color) {
    if(x > N) {
        ans[color] = max(ans[color], n);
        return;
    }

    int leftx = (y-1) > (x-1) ? 1 : x-(y-1);
    int rightx = (N-y) > (x-1) ? 1 : x-(N-y);
    int lefty = (y-1) > (x-1) ? y-(x-1) : 1;
    int righty = (N-y) > (x-1) ? y+(x-1) : N;

    int nx = 0;
    int ny = 0;
    if(N % 2 == 1) {
        nx = (y==N || y==N-1) ? x+1 : x;
        ny = (y==N) ? 2 : y+2;
        if(ny > N) ny = 1;
    }
    else {
        nx = (y==N || y==N-1) ? x+1 : x;
        ny = (y==N) ? 1 : y+2;
        if(ny > N) ny = 2;
    } 

    if(map[x][y] && !bishop[x][y] && isSafe(leftx, lefty, rightx, righty)) {
        bishop[x][y] = true;
        check[leftx][lefty][0] = true;
        check[rightx][righty][1] = true;
        BT(nx, ny, n+1, color);
        bishop[x][y] = false;
        check[leftx][lefty][0] = false;
        check[rightx][righty][1] = false;
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