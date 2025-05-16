#include <iostream>
#include <queue>

using namespace std;

struct Snake {
    int dir; // 방향 0 : 오른쪽, 1 : 위, 2 : 왼쪽, 3 : 아래
    int headX, headY, tailX, tailY; // 머리와 꼬리 위치
    bool body[101][101]; // 현재 뱀의 몸 상태
    queue<int> path; // 지나온 경로
};

int N, K, L;
bool apple[101][101]; // 사과
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, char>> q;
Snake snake;

void init() {
    snake.dir = 0;
    snake.headX = snake.headY = snake.tailX = snake.tailY = 1;
    snake.body[1][1] = true;
}

bool checkGameOver() {
    if (snake.headX < 1 || snake.headY < 1 || snake.headX > N || snake.headY > N) return true; // 벽에 부딪힐 경우
    if (snake.body[snake.headX][snake.headY]) return true; // 몸에 부딪힐 경우
    return false;
}

void input() {
    cin >> N >> K;
    for (int i=0; i<K; i++) {
        int x, y;
        cin >> x >> y;
        apple[x][y] = true;
    }
    cin >> L;
    for (int i=0; i<L; i++) {
        int x; char c;
        cin >> x >> c;
        q.push({x, c});
    }
}

void solve() {
    init(); // 뱀 초기화

    int time = 0;
    while(1) {
        time++; // 시간 증가

        // 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        snake.headX += dx[snake.dir];
        snake.headY += dy[snake.dir];

        // 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
        if (checkGameOver()) break;

        snake.body[snake.headX][snake.headY] = true; // 몸 상태 갱신
        snake.path.push(snake.dir);

        // 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        // 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        if (apple[snake.headX][snake.headY]) apple[snake.headX][snake.headY] = false;
        else {
            snake.body[snake.tailX][snake.tailY] = false;
            snake.tailX += dx[snake.path.front()];
            snake.tailY += dy[snake.path.front()];
            snake.path.pop();
        }

        // 방향 전환
        if (!q.empty() && q.front().first == time) {
            char op = q.front().second;
            q.pop();
            if (op == 'L') snake.dir = (snake.dir+1)%4;
            else snake.dir = (snake.dir+3)%4;
        }
    };

    cout << time << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}