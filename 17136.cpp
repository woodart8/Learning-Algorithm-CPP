#include <iostream>
#include <vector>

using namespace std;

int paper[10][10];
int colorPaper[6] = {0,5,5,5,5,5};
int answer = 1e9;

// 10x10 종이가 전부 채워졌는지 검사하는 함수
bool isFilled() {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (paper[i][j]) return false;
        }
    }
    return true;
}

// (x, y)를 기준으로 size x size 범위가 색종이로 채워질 수 있는지 검사하는 함수 
bool canFill(int x, int y, int size) {
    if (x+size-1 >= 10 || y+size-1 >= 10) return false;
    for (int i=x; i<=x+size-1; i++) {
        for (int j=y; j<=y+size-1; j++) {
            if (!paper[i][j]) return false;
        }
    }
    return true;
}

// (x, y)를 기준으로 size x size 범위를 색종이로 채우는 함수 
void fill(int x, int y, int size) {
    if (x+size-1 >= 10 || y+size-1 >= 10) return;
    for (int i=x; i<=x+size-1; i++) {
        for (int j=y; j<=y+size-1; j++) {
            paper[i][j] = 0;
        }
    }
}

// (x, y)에 붙어있는 size 크기의 색종이를 제거하는 함수 
void undo(int x, int y, int size) {
    if (x+size-1 >= 10 || y+size-1 >= 10) return;
    for (int i=x; i<=x+size-1; i++) {
        for (int j=y; j<=y+size-1; j++) {
            paper[i][j] = 1;
        }
    }    
}

void bt(int cnt) {
    if (cnt > 25) return; // 이미 모든 색종이를 소모했을 경우
    if (isFilled()) {
        answer = min(answer, cnt);
        return;
    } // 완벽하게 붙인 경우
    if (cnt >= answer) return; // 이미 최소값과 같거나 많으면 더 붙여 볼 필요가 없다.
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (paper[i][j]) {
                for (int k=1; k<=5; k++) {
                    if (colorPaper[k] && canFill(i,j,k)) {
                        colorPaper[k]--;
                        fill(i,j,k);
                        bt(cnt+1);
                        undo(i,j,k);
                        colorPaper[k]++;
                    }
                }
                return; 
                // 1~5 크기의 색종이를 다 붙여봤기 때문에 더 조사할 필요가 없다.
                // 색종이를 붙이는데 성공한 경우에는 다음 단계에서 조사할 것이고
                // 색종이를 붙이는데 실패한 경우에는 이전 단계에서 잘못 붙인 것이다.
            }
        }
    }
}

void input() {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            cin >> paper[i][j];
        }
    }
}

void solve() {
    bt(0);
    if (answer == 1e9) cout << -1 << '\n';
    else cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}