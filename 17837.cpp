#include <iostream>
#include <vector>

using namespace std;

struct horse {
    int x, y, dir;
} h[10];

int N,K;
int map[14][14];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int turn[] = {0, 2, 1, 4 ,3};
vector<int> info[14][14];

int move(int i) {
    int next_x = h[i].x + dx[h[i].dir];
    int next_y = h[i].y + dy[h[i].dir];
    if(next_x < 1 || next_y < 1 || next_x > N || next_y > N || map[next_x][next_y] == 2) {
        h[i].dir = turn[h[i].dir];
        next_x = h[i].x + dx[h[i].dir];
        next_y = h[i].y + dy[h[i].dir];
        if(next_x < 1 || next_y < 1 || next_x > N || next_y > N || map[next_x][next_y] == 2) {
            return 0;
        } 
    }
    vector<int>& cur = info[h[i].x][h[i].y];
    vector<int>& next = info[next_x][next_y];
    int idx = 0;
    for(int j=0; j<cur.size(); j++) {
        if(cur[j] == i) idx = j;
    }

    if(map[next_x][next_y] == 0) {
        next.insert(next.end(), cur.begin()+idx, cur.end());
    }
    else if(map[next_x][next_y] == 1) {
        next.insert(next.end(), cur.rbegin(), cur.rend()-idx);
    }

    for(int i=0; i<next.size(); i++) {
        h[next[i]].x = next_x;
        h[next[i]].y = next_y;
    }
    cur.erase(cur.begin()+idx, cur.end());
    return next.size();
}

int simulation() {
    for(int i=1; i<=1000; i++) {
        for(int j=0; j<K; j++) {
            if(move(j) >= 4) return i;
        }
    }
    return -1;
}

int main() {
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<K; i++) {
        cin >> h[i].x >> h[i].y >> h[i].dir;
        info[h[i].x][h[i].y].push_back(i);
    }

    cout << simulation();

    return 0;
}