#include <iostream>
#include <cmath>

using namespace std;

int N, R1, C1, R2, C2;

void input() {
    cin >> N >> R1 >> C1 >> R2 >> C2;
}

char getAlpha(int n, int x, int y) {
    int dx = abs(x % (n * 2 - 1) - (n * 2 - 1) / 2);
    int dy = abs(y % (n * 2 - 1) - (n * 2 - 1) / 2);

    if (dx + dy >= n) return '.';

    return 'a' + (dx + dy) % 26;
}

void draw(int n, int x1, int y1, int x2, int y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    for (int i=x1; i<=x2; i++) {
        for (int j=y1; j<=y2; j++) {
            cout << getAlpha(n, i, j);
        }
        cout << '\n';
    }
}

void solve() {
    draw(N, R1, C1, R2, C2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}