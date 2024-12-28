#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int A[21][21];
int ans = 1e9;

void input() {
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

void coloring(int x, int y, int d1, int d2) {
    int area[21][21] = {0};
    int cnt[6] = {0};
    int dy = y;

    // 1번 경계선
    for (int dx=x; dx<=x+d1; dx++, dy--) {
        area[dx][dy] = 5;
    }

    // 2번 경계선
    dy = y;
    for (int dx=x; dx<=x+d2; dx++, dy++) {
        area[dx][dy] = 5;
    }

    // 3번 경계선
    dy = y-d1;
    for (int dx=x+d1; dx<=x+d1+d2; dx++, dy++) {
        area[dx][dy] = 5;
    }

    // 4번 경계선
    dy = y+d2;
    for (int dx=x+d2; dx<=x+d1+d2; dx++, dy--) {
        area[dx][dy] = 5;
    }

    // 1번 구역 색칠
    for (int r=1; r<x+d1; r++) {
        for (int c=1; c<=y; c++) {
            if (area[r][c] == 5) break;
            area[r][c] = 1;
        }
    }

    // 2번 구역 색칠
    for (int c=y+1; c<=N; c++) {
        for (int r=1; r<=x+d2; r++) {
            if (area[r][c] == 5) break;
            area[r][c] = 2;
        }
    }

    // 3번 구역 색칠
    for (int c=1; c<y-d1+d2; c++) {
        for (int r=N; r>=x+d1; r--) {
            if (area[r][c] == 5) break;
            area[r][c] = 3;
        }
    }

    // 4번 구역 색칠
    for (int r=N; r>x+d2; r--) {
        for (int c=N; c>=y-d1+d2; c--) {
            if (area[r][c] == 5) break;
            area[r][c] = 4;
        }
    }

    // 5번 구역 색칠
    for (int r=1; r<=N; r++) {
        for (int c=1; c<=N; c++) {
            if(!area[r][c]) area[r][c] = 5;
            cnt[area[r][c]] += A[r][c];
        }
    }

    int minN = 1e9;
    int maxN = 0;
    
    // 인구 수 최대, 최소 계산
    for (int i=1; i<=5; i++) {
        if (cnt[i] < minN) minN = cnt[i];
        if (cnt[i] > maxN) maxN = cnt[i];
    }

    // 정답 갱신
    ans = min(ans, maxN-minN);
}

void solve() {
    for (int x=1; x<=N; x++) {
        for (int y=1; y<=N; y++) {
            for (int d1=1; d1<=N; d1++) {
                for (int d2=1; x+d1+d2<=N && y-d1>=1 && y+d2<=N; d2++) {
                    coloring(x,y,d1,d2);
                }
            }
        }
    }
}

void output() {
    printf("%d", ans);
}

int main() {
    input();
    solve();
    output();

    return 0;
}