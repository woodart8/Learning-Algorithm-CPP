#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int map[20][20];
int answer;

// 방향: 0: 오른쪽, 1: 위, 2: 왼쪽, 3: 아래
// 방향 이동에 따라 행, 열 순서와 방향 다름
void compressAndMerge(int dir) {
    queue<int> q;

    for(int i = 0; i < N; i++) {
        // 방향에 따라 정렬 방향 설정
        int start = (dir == 0 || dir == 3) ? N-1 : 0;
        int end = (dir == 0 || dir == 3) ? -1 : N;
        int step = (dir == 0 || dir == 3) ? -1 : 1;

        // 큐에 비어있지 않은 값 삽입 + 초기화
        for(int j=start; j!=end; j+=step) {
            int val;
            if(dir == 0 || dir == 2) val = map[i][j]; // 좌우 이동
            else val = map[j][i]; // 상하 이동

            if(val > 0) q.push(val);
            if(dir == 0 || dir == 2) map[i][j] = 0;
            else map[j][i] = 0;
        }

        int cur = (dir == 0 || dir == 3) ? N - 1 : 0;
        while(!q.empty()) {
            int data = q.front(); 
            q.pop();

            int& target = (dir == 0 || dir == 2) ? map[i][cur] : map[cur][i];

            if(target == 0) {
                target = data;
            } else if(target == data) {
                target *= 2;
                cur += (dir == 0 || dir == 3) ? -1 : 1;
            } else {
                cur += (dir == 0 || dir == 3) ? -1 : 1;
                int& next = (dir == 0 || dir == 2) ? map[i][cur] : map[cur][i];
                next = data;
            }
        }
    }
}

// DFS로 최대 5번 이동하여 최대값 탐색
void dfs(int cnt) {
    if(cnt == 5) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                answer = max(answer, map[i][j]);
            }
        }
        return;
    }

    int copyMap[20][20];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            copyMap[i][j] = map[i][j];
        }
    }

    for(int dir=0; dir<4; dir++) {
        compressAndMerge(dir);
        dfs(cnt+1);
        // 상태 복원
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                map[i][j] = copyMap[i][j];
            }
        }
    }
}

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }
}

void solve() {
    dfs(0);
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}
