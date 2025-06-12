#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int map[8][8];
vector<pair<int,int>> virus;
int answer;

// 바이러스 퍼뜨리기
void spreadVirus(int tempMap[8][8]) {
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    queue<pair<int,int>> q;

    for (auto v : virus)
        q.push(v);

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || tempMap[nx][ny] != 0) continue;
            tempMap[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
}

// 안전 구역 계산
int calcSafeSpace(int tempMap[8][8]) {
    int count = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(tempMap[i][j] == 0) count++;
    return count;
}

// 백트래킹 (벽 세우기)
void bt(int start, int count) {
    if (count == 3) {
        int tempMap[8][8];
        memcpy(tempMap, map, sizeof(map));
        spreadVirus(tempMap);
        answer = max(answer, calcSafeSpace(tempMap));
        return;
    }

    for (int i=start; i<N*M; i++) {
        int x = i / M;
        int y = i % M;
        if (map[x][y] != 0) continue;
        map[x][y] = 1;
        bt(i+1, count+1);
        map[x][y] = 0;
    }
}

void input() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2)
                virus.push_back({i, j});
        }
    }
}

void solve() {
    bt(0, 0);
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    input();
    solve();
    return 0;
}