#include <iostream>

using namespace std;

int N, L;
int map[100][100];

bool checkPath(int* arr) {
    int flat = 1;
    bool isSkipped = false;

    for (int i=1; i<N; i++) {
        int diff = arr[i] - arr[i - 1];
        // 평지
        if (diff == 0) {
            flat++;
            if (isSkipped && flat >= L) {
                isSkipped = false;
                flat = 0;
            }
        } 
        // 오르막
        else if (diff == 1) {
            if (flat >= L) flat = 1;
            else return false;
        } 
        // 내리막
        else if (diff == -1) {
            if (isSkipped) return false;

            // 즉시 설치 가능한 경우
            if (L == 1) {
                flat = 0;
                continue;
            }
            
            isSkipped = true;
            flat = 1;
        }
        else return false;
    }

    return !isSkipped;
}

void input() {
    cin >> N >> L;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
}

void solve() {
    int answer = 0;
    int temp[100];

    // 행 검사
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            temp[j] = map[i][j];
        if (checkPath(temp)) answer++;
    }

    // 열 검사
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++)
            temp[i] = map[i][j];
        if (checkPath(temp)) answer++;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}