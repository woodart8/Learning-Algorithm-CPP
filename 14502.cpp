#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[9][9];
int dx[] = {0, -1, 0 ,1};
int dy[] = {1, 0, -1, 0};
int ans;
vector<pair<int,int>> virus;

int spreadVirus() {
    int count = 0;
    queue<pair<int,int>> q;
    for(int i=0; i<virus.size(); i++) {
        q.push({virus[i].first, virus[i].second});
    }

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        map[now_x][now_y] = 2;

        for(int i=0; i<4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if(next_x < 1 || next_y < 1 || next_x > N || next_y > M || map[next_x][next_y] != 0) continue;
            q.push({next_x,next_y});
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(map[i][j] == 0) count++;
        }
    }
    return count;
}

void setWall(int count) {
    if(count == 3) {
        ans = max(ans, spreadVirus());
        return;
    }

    int copyMap[9][9];
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            copyMap[i][j] = map[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                setWall(count+1);
                for(int r=1; r<=N; r++) {
                    for(int c=1; c<=M; c++) {
                        map[r][c] = copyMap[r][c];
                    }
                }
            }
        }
    }
}

int simulation() {
    setWall(0);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) virus.push_back({i,j});
        }
    }

    cout << simulation();
    return 0;
}