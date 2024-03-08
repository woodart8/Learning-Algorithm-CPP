#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,x,y,K;
int map[20][20];
vector<int> num(7,0);
queue<int> dir;
int dx[] = {0, 0, 0, -1, 1}; //1: 동, 2: 서, 3: 북, 4: 남
int dy[] = {0, 1, -1, 0, 0};
int top = 1, bottom = 6, east = 3, west = 4, north = 2, south = 5;
int count = 0;
void simulation() {
    while(!dir.empty()) {
        int idx = dir.front();
        dir.pop();
        count++;
        int next_x = x+dx[idx];
        int next_y = y+dy[idx];
        if(next_x < 0 || next_x > N-1 || next_y < 0 || next_y > M-1) continue;
        x = next_x;
        y = next_y;
        switch (idx) {
            case 1:
                swap(num[top], num[west]);
                swap(num[west], num[bottom]);
                swap(num[bottom], num[east]);
                break;
            case 2:
                swap(num[top], num[east]);
                swap(num[east], num[bottom]);
                swap(num[bottom], num[west]);
                break;
            case 3:
                swap(num[top], num[south]);
                swap(num[south], num[bottom]);
                swap(num[bottom], num[north]);
                break;
            case 4:
                swap(num[top], num[north]);
                swap(num[north], num[bottom]);
                swap(num[bottom], num[south]);
                break;
        }

        if(map[x][y] > 0) {
            num[bottom] = map[x][y];
            map[x][y] = 0;
        }
        else map[x][y] = num[bottom];
        cout << num[top];
        if(count < K) cout << '\n';
    }

    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int d;
    cin >> N >> M >> x >> y >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
    for(int i=0; i<K; i++) {
        cin >> d;
        dir.push(d);
    }

    simulation();
    return 0;
}