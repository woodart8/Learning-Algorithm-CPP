#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_ARCHER 3

int N,M,D;
int originEnemy; // 초기 적 숫자
int gameEnemy; // 게임 내 적 숫자
bool originField[15][15]; // 필드 원본
bool gameField[15][15]; // 게임 진행용 복사본
vector<int> archer; // 궁수가 배치된 열 번호
int answer;

struct cmp {
    // pair<거리, pair<x, y>>
    // 거리가 가까운 순 -> 같을 경우에는 y가 작은 순 (더 왼쪽)
    bool operator()(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b) {
        if (a.first != b.first) {
            return a.first > b.first;
        } else {
            return a.second.second > b.second.second;
        }
    }
};

void init() {
    // 게임 필드 초기화
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            gameField[i][j] = originField[i][j];
        }
    }
    gameEnemy = originEnemy;
}

bool isEnemyAlive() {
    // 게임 필드에 적이 살아있는지 검사
    return gameEnemy > 0;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x2-x1) + abs(y2-y1);
}

int attack() {
    int point = 0;
    vector<pair<int,int>> attackedEnemy; // 공격받은 적 정보 저장
    for (int a : archer) {
        int x = N;
        int y = a;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, cmp> candidate; // 거리, 좌표(x,y)
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                int d = dist(x,y,i,j);
                if (gameField[i][j] && d <= D) {
                    candidate.push({d,{i,j}});
                } // 해당 좌표에 적이 존재하고 사거리 안에 들어와 있는 경우 후보군에 추가
            }
        }

        // 후보군이 존재하면 가장 우선순위가 높은 적을 공격
        if ((int)candidate.size() > 0) attackedEnemy.push_back(candidate.top().second);
    }

    // 공격받은 적 제거하고 점수 계산
    for (pair<int,int> e : attackedEnemy) {
        int x = e.first;
        int y = e.second;
        if (gameField[x][y]) {
            point++;
            gameField[x][y] = false;
            gameEnemy--;
        }
    }

    return point;
}

void enemyMove() {
    // 적을 한칸씩 내린다
    for (int i=N-1; i>=1; i--) {
        for (int j=0; j<M; j++) {
            if (i == N-1 && gameField[i][j]) gameEnemy--;
            gameField[i][j] = gameField[i-1][j];
        }
    }

    // 가장 위는 적이 없으므로 false로 채운다.
    for (int i=0; i<M; i++) {
        gameField[0][i] = false;
    }
}

void play() {
    int point = 0;
    // 적이 남아있는 동안 반복
    while(isEnemyAlive()) {
        point += attack(); // 궁수가 먼저 공격한다.
        enemyMove(); // 그다음 적이 움직인다.
    }

    answer = max(answer, point);
}

void placeArcher(int last, int cnt) {
    // 궁수 숫자가 최대치가 되면 게임 시작
    if (cnt == MAX_ARCHER) {
        init();
        play();
        return;
    }

    for (int i=last+1; i<M; i++) {
        archer.push_back(i);
        placeArcher(i, cnt+1);
        archer.pop_back();
    }
}

void input() {
    cin >> N >> M >> D;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> originField[i][j];
            if (originField[i][j]) originEnemy++;
        }
    }
}

void solve() {
    placeArcher(-1, 0);
    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}