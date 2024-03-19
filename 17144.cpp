#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[51][51];
vector<pair<int, pair<int,int>>> dust;
int R,C,T;
vector<pair<int,int>> cleaner;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

void spread() {
    memset(map, 0, sizeof(map));
    for(int i=0; i<dust.size(); i++) {
        map[dust[i].second.first][dust[i].second.second] = dust[i].first;
    }

    for(int i=0; i<dust.size(); i++) {
        int now_x = dust[i].second.first;
        int now_y = dust[i].second.second;
        int cnt = 0;
        for(int j=0; j<4; j++) {
            bool flag = false;
            int next_x = now_x + dx[j];
            int next_y = now_y + dy[j];
            if(next_x < 1 || next_y < 1 || next_x > R || next_y > C) continue;
            if((next_x == cleaner[0].first && next_y == cleaner[0].second) || (next_x == cleaner[1].first && next_y == cleaner[1].second)) continue;
            map[next_x][next_y] += dust[i].first/5;
            cnt++;
        }
        if(cnt > 0) map[now_x][now_y] -= (dust[i].first/5)*cnt;
    }

    dust.clear();
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(map[i][j] > 0) dust.push_back({map[i][j],{i,j}});
        }
    }
    return;
}

void clean() {
    int topCleanerX = cleaner[0].first;
    int topCleanerY = cleaner[0].second;
    int bottomCleanerX = cleaner[1].first;
    int bottomCleanerY = cleaner[1].second;
    for(int i=0; i<dust.size(); i++) {
        if(dust[i].second.first == topCleanerX && dust[i].second.second < topCleanerY) {
            dust[i].second.second++;
        } // 위 청소기랑 같은줄 더 뒤쪽
        else if(dust[i].second.first == topCleanerX && dust[i].second.second > topCleanerY) {
            if(dust[i].second.second+1 <= C)
                dust[i].second.second++;
            else dust[i].second.first--;
        } // 위 청소기랑 같은줄 더 앞쪽
        else if(dust[i].second.first == bottomCleanerX && dust[i].second.second < bottomCleanerY) {
            dust[i].second.second++;
        } // 아래 청소기랑 같은줄 더 뒤쪽
        else if(dust[i].second.first == bottomCleanerX && dust[i].second.second > bottomCleanerY) {
            if(dust[i].second.second+1 <= C)
                dust[i].second.second++;
            else dust[i].second.first++;
        } // 아래 청소기랑 같은줄 더 앞쪽
        else if(dust[i].second.first == 1 || dust[i].second.first == R) {
            if(dust[i].second.second-1 >= 1)
                dust[i].second.second--;
            else {
                if(dust[i].second.first == 1) dust[i].second.first++;
                else dust[i].second.first--;
            }
        } //먼지의 x 위치가 맨 위나 맨 아래일 경우
        else if(dust[i].second.second == 1 || dust[i].second.second == C) {
            if(dust[i].second.second == 1) {
                if(dust[i].second.first < topCleanerX) dust[i].second.first++;
                else if(dust[i].second.first > bottomCleanerX) dust[i].second.first--;
            }
            else {
                if(dust[i].second.first < topCleanerX) dust[i].second.first--;
                else if(dust[i].second.first > bottomCleanerX) dust[i].second.first++;
            }
        } //먼지의 x 위치가 맨 위나 맨 아래, 청소기의 위치가 아니면서 y 위치가 맨 왼쪽이나 오른쪽일 경우 

        if(dust[i].second.first == topCleanerX && dust[i].second.second == topCleanerY) dust[i].first = 0;
        else if(dust[i].second.first == bottomCleanerX && dust[i].second.second == bottomCleanerY) dust[i].first = 0;
    }

    dust.erase(remove_if(dust.begin(),dust.end(), [](auto x){ return x.first == 0; }), dust.end());
}

int simulation(int time) {
    int ans = 0;
    while(time) {
        spread();
        clean();
        time--;
    }
    for(int i=0; i<dust.size(); i++) {
        ans += dust[i].first;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> T;
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) {
                cleaner.push_back({i,j});
            }
            else if(map[i][j] > 0) {
                dust.push_back({map[i][j],{i,j}});
            }
            else continue;
        }
    }

    cout << simulation(T) << endl;

    return 0;
}