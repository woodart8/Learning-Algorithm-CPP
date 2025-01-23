#include <iostream>
#include <vector>

using namespace std;

int N,M;
char map[50][50];

void input() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
}

int findBox(int x, int y) {
    int length = 1;
    for (int i=1; x+i<N && y+i<M; i++) {
        if (map[x+i][y] == map[x][y] && map[x+i][y+i] == map[x][y] && map[x][y+i] == map[x][y]) {
            length = max(length, i+1);
        }
    }

    return length * length;
}

void solve() {
    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            ans = max(ans, findBox(i,j));
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}