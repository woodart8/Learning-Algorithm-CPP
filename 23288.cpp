#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int map[21][21]; // 지도 정보

class Dice {
    public:
        int dir; // 굴리는 방향 1: 위, 2: 아래, 3: 왼쪽, 4: 오른쪽
        int x, y; // 주사위 위치
        int top, bottom, front, back, left, right; // 상, 하, 전, 후, 좌, 우

        // 생성자
        Dice(int _dir, int _x, int _y, int _top, int _bottom, int _front, int _back, int _left, int _right) {
            this->dir = _dir;
            this->x = _x;
            this->y = _y;
            this->top = _top;
            this->bottom = _bottom;
            this->front = _front;
            this->back = _back;
            this->left = _left;
            this->right = _right;
        }

        // 주사위 굴리기
        void roll() {
            checkValid(); // 이동에 대한 유효성 검사

            int temp;
            switch (this->dir) {
                case 1: temp = this->back;
                        this->back = this->top; 
                        this->top = this->front;
                        this->front = this->bottom;
                        this->bottom = temp;
                        this->x--;
                        break;
                case 2: temp = this->back;
                        this->back = this->bottom; 
                        this->bottom = this->front;
                        this->front = this->top;
                        this->top = temp;
                        this->x++;
                        break;
                case 3: temp = this->left;
                        this->left = this->top; 
                        this->top = this->right;
                        this->right = this->bottom;
                        this->bottom = temp;
                        this->y--;
                        break;
                case 4: temp = this->right;
                        this->right = this->top; 
                        this->top = this->left;
                        this->left = this->bottom;
                        this->bottom = temp;
                        this->y++;
                        break;
            }
        }

        // 정수 A와 B를 비교하여 다음 이동 방향 결정
        void changeDir() {
            int A = this->bottom;
            int B = map[x][y];
            if (A > B) turnClockwise();
            else if (A < B) turnCounterClockwise();
        }

    private:
        // 이동 방향에 칸이 없다면, 이동 방향을 반대로 변경
        void checkValid() {
            switch (this->dir) {
                case 1: if (this->x == 1) this->dir = 2;
                        break;
                case 2: if (this->x == N) this->dir = 1;
                        break;
                case 3: if (this->y == 1) this->dir = 4;
                        break;
                case 4: if (this->y == M) this->dir = 3;
                        break;
            }
        }

        // 이동 방향을 90도 시계 방향으로 회전
        void turnClockwise() {
            switch (this->dir) {
                case 1: this->dir = 4; break;
                case 2: this->dir = 3; break;
                case 3: this->dir = 1; break;
                case 4: this->dir = 2; break;
            }
        }

        // 이동 방향을 90도 반시계 방향으로 회전
        void turnCounterClockwise() {
            switch (this->dir) {
                case 1: this->dir = 3; break;
                case 2: this->dir = 4; break;
                case 3: this->dir = 2; break;
                case 4: this->dir = 1; break;
            }
        }

};


// 너비 우선 탐색
int bfs(int x, int y) {
    int ret = 0;
    int val = map[x][y];
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    bool visited[21][21] = {false};
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        ret++;

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > M) continue; // 지도 밖인 경우
            if (visited[nx][ny] || map[nx][ny] != val) continue; // 이미 방문 or 지도의 숫자가 val과 다른 경우
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return ret;
}

void input() {
    cin >> N >> M >> K;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> map[i][j];
        }
    }
}

void solve() {
    int answer = 0;
    Dice dice(4, 1, 1, 1, 6, 5, 2, 4, 3); // 주사위 초기화

    // K번 이동
    for(int i=0; i<K; i++) {
        dice.roll(); // 주사위 굴리기 
        answer += map[dice.x][dice.y]*bfs(dice.x, dice.y); // 점수 누적
        dice.changeDir(); // 다음 방향 결정
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}