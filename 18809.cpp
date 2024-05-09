#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 50

int N,M,G,R;

int map[MAX][MAX]; //초기 맵
int candsz;
int brute[10];
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int,int>> possible; 
int ans;

int BFS() {
    int cnt = 0; // 꽃 개수
    queue<pair<int,int>> q; //빨간색 좌표 큐

    pair<int,int> state[MAX][MAX];

    for(int i=0; i<possible.size(); i++) {
        if(brute[i] == GREEN || brute[i] == RED){
            state[possible[i].first][possible[i].second] = {0, brute[i]};
            q.push(possible[i]);
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int curtime = state[x][y].first;
        int curcolor = state[x][y].second;
        q.pop();
        if(curcolor == FLOWER) continue;
        for(int j=0; j<4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == 0) continue;
            if(state[nx][ny].second == EMPTY) {
                state[nx][ny] = {curtime+1, curcolor};
                q.push({nx,ny});
            }
            else if(state[nx][ny].second == GREEN) {
                if(curcolor == RED && state[nx][ny].first == curtime+1) {
                    cnt++;
                    state[nx][ny].second = FLOWER;
                }
            }
            else if(state[nx][ny].second == RED) {
                if(curcolor == GREEN && state[nx][ny].first == curtime+1) {
                    cnt++;
                    state[nx][ny].second = FLOWER;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> G >> R;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) possible.push_back({i,j});
        }
    }

    candsz = possible.size();
    fill(brute+candsz-G-R, brute+candsz-R,GREEN);
    fill(brute+candsz-R, brute+candsz,RED);
    do{
      ans = max(ans, BFS());
    }while(next_permutation(brute, brute+candsz));
    cout << ans << '\n';
    return 0;
}