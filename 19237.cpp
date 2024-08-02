#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 20
#define MAX_DIR 4

struct Shark {
    int num;
    int x;
    int y;
    int dir;
    vector<vector<int>> priority;

    bool operator<(const Shark &shark) const {
        return num < shark.num;
    } 
};

struct Scent{
    int num;
    int x;
    int y;
    int timeLeft;
};

int N,M,k;
vector<Shark> sharks;
Scent scents[MAX_N][MAX_N];
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};

void input() {
    cin >> N >> M >> k;
    
    vector<pair<int,pair<int,int>>> sharkLocation(M);
    vector<int> initDirection(M);
    vector<vector<vector<int>>> priorities(M, vector<vector<int>>(MAX_DIR, vector<int>(MAX_DIR)));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int num;
            cin >> num;
            if(num > 0) sharkLocation[num-1] = {num,{i,j}};
        }
    }

    for(int i=0; i<M; i++) {
        cin >> initDirection[i];
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < MAX_DIR; ++j) {
            for (int l = 0; l < MAX_DIR; ++l) {
                cin >> priorities[i][j][l];
            }
        }
    }

    for(int i=0; i<M; i++) {
        int num = sharkLocation[i].first;
        int x = sharkLocation[i].second.first;
        int y = sharkLocation[i].second.second;
        int dir = initDirection[num-1];
        sharks.push_back({num,x,y,dir,priorities[num-1]});
        scents[x][y] = {num,x,y,k};
    }
    
    sort(sharks.begin(), sharks.end());
}   

void moveShark(Shark& shark) {
    for(int i=0; i<MAX_DIR; i++) {
        int ndir = shark.priority[shark.dir-1][i];
        int nx = shark.x + dx[ndir];
        int ny = shark.y + dy[ndir];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && scents[nx][ny].num == 0) {
            shark.x = nx;
            shark.y = ny;
            shark.dir = ndir;
            return;
        }
    }

    for(int i=0; i<shark.priority.size(); i++) {
        int ndir = shark.priority[shark.dir-1][i];
        int nx = shark.x + dx[ndir];
        int ny = shark.y + dy[ndir];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && scents[nx][ny].num == shark.num) {
            shark.x = nx;
            shark.y = ny;
            shark.dir = ndir;
            return;
        }
    }
}

void chaseOut() {
    vector<Shark> newSharks;
    for (const Shark& shark : sharks) {
        if (scents[shark.x][shark.y].num == shark.num) {
            newSharks.push_back(shark);
        }
    }
    sharks = move(newSharks);
}

void decScentTime() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (scents[i][j].timeLeft > 0 && --scents[i][j].timeLeft == 0) {
                scents[i][j].num = 0;
            }
        }
    }
}

void spreadScent(Shark& shark) {
    scents[shark.x][shark.y] = {shark.num,shark.x,shark.y,k};
}


void solve() {
    for(int t=0; t<=1000; t++) {
        if(sharks.size() == 1) {
            cout << t << '\n';
            return;
        }
        for(Shark& shark : sharks) {
            moveShark(shark);
        }
        decScentTime();
        for(auto it = sharks.rbegin(); it != sharks.rend(); ++it) {
            spreadScent(*it);
        }
        chaseOut();
    }

    cout << "-1" << '\n';
}

int main() {
    input();
    solve();
    return 0;
}