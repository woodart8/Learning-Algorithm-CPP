#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,L,R;
int map[50][50];
bool visited[50][50];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
vector<pair<int,int>> u;
bool flag = false;
int day = 0;

int bfs(int x, int y) {
    int uni = 1;
    int population = map[x][y];
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        u.push_back({now_x, now_y});
        q.pop();
        for(int i=0; i<4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || visited[next_x][next_y] || abs(map[now_x][now_y] - map[next_x][next_y]) > R || abs(map[now_x][now_y] - map[next_x][next_y]) < L) 
                continue;
            population += map[next_x][next_y];
            uni++;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }

    return population / uni;
}

void move() {
    memset(visited, false, sizeof(visited));
    flag = false;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!visited[i][j]) {
                int avg_pop = bfs(i,j);
                for(int k=0; k<u.size(); k++) {
                    if(avg_pop != map[u[k].first][u[k].second]) flag = true;
                    map[u[k].first][u[k].second] = avg_pop;
                }
                u.clear();
            }
        }
    }
}

int main() {
    cin >> N >> L >> R;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    do {
        move();
        if(flag) day++;
    } while(flag);

    cout << day << endl;
    return 0;
}