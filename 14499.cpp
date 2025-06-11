#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K;
int map[20][20];

class Dice {
    public:
        int x, y; // 주사위 위치
        int top, bottom, front, back, left, right; // 상, 하, 전, 후, 좌, 우

        // 생성자
        Dice(int _x, int _y, int _top, int _bottom, int _front, int _back, int _left, int _right) {
            this->x = _x;
            this->y = _y;
            this->top = _top;
            this->bottom = _bottom;
            this->front = _front;
            this->back = _back;
            this->left = _left;
            this->right = _right;
        }

        // 굴리는데 성공할 경우 true, 실패하면 false
        bool roll(int dir) {
            if(!checkValid(dir)) return false; // 벽에 막혀 못 굴리는 경우

            // 굴리는 방향 : 동쪽 1, 서쪽 2, 북쪽 3, 남쪽 4
            int temp;
            switch (dir) {
                case 1: temp = right;
                        right = top;
                        top = left;
                        left = bottom;
                        bottom = temp;
                        y++;
                        return true;
                case 2: temp = left;
                        left = top;
                        top = right;
                        right = bottom;
                        bottom = temp;
                        y--;
                        return true;
                case 3: temp = back;
                        back = top;
                        top = front;
                        front = bottom;
                        bottom = temp;
                        x--;
                        return true;
                case 4: temp = front;
                        front = top;
                        top = back;
                        back = bottom;
                        bottom = temp;
                        x++;
                        return true;
            }

            return false;
        }

        // 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 
        // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
        void update() {
            if (map[x][y] == 0) map[x][y] = this->bottom;
            else {
                this->bottom = map[x][y];
                map[x][y] = 0;
            }
        }

    private:
        // 다음 이동 위치가 벽에 막혀있으면 false, 그 외에는 true
        bool checkValid(int dir) {
            switch (dir) {
                case 1: if (y == M-1) return false;
                        break;
                case 2: if (y == 0) return false;
                        break;
                case 3: if (x == 0) return false;
                        break;
                case 4: if (x == N-1) return false;
                        break;
            }
            return true;
        }
};

void input() {
    cin >> N >> M >> x >> y >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
}

void solve() {
    Dice dice(x,y,0,0,0,0,0,0);
    for (int i=0; i<K; i++) {
        int op;
        cin >> op;
        // 굴리는 게 성공할 경우
        if (dice.roll(op)) {
            dice.update(); // 주사위 업데이트
            cout << dice.top << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    input();
    solve();
    return 0;
}