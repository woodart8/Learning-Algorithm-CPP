#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N;
int map[20][20];
int ans = 0;

void move(int idx) {
    queue<int> q;

    if(idx == 0) {
        for(int i=0; i<N; i++) {
            for(int j=N-1; j>=0; j--) {
                if(map[i][j] > 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }
            int now = N-1;
            while(!q.empty()) {
                int data = q.front();
                q.pop();
                if(map[i][now] == 0) {
                    map[i][now] = data;
                }
                else if(map[i][now] == data) {
                    map[i][now] *= 2;
                    now--;
                }
                else {
                    now--;
                    map[i][now] = data;
                }
            }
        }
    }
    else if(idx == 1) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[j][i] > 0)
                    q.push(map[j][i]);
                map[j][i] = 0;
            }
            int now = 0;
            while(!q.empty()) {
                int data = q.front();
                q.pop();
                if(map[now][i] == 0) {
                    map[now][i] = data;
                }
                else if(map[now][i] == data) {
                    map[now][i] *= 2;
                    now++;
                }
                else {
                    now++;
                    map[now][i] = data;
                }
            }
        }
    }
    else if(idx == 2) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] > 0)
                    q.push(map[i][j]);
                map[i][j] = 0;
            }
            int now = 0;            
            while(!q.empty()) {
                int data = q.front();
                q.pop();
                if(map[i][now] == 0) {
                    map[i][now] = data;
                }
                else if(map[i][now] == data) {
                    map[i][now] *= 2;
                    now++;
                }
                else {
                    now++;
                    map[i][now] = data;
                }
            }
        }
    }
    else if(idx == 3) {
        for(int i=0; i<N; i++) {
            for(int j=N-1; j>=0; j--) {
                if(map[j][i] > 0)
                    q.push(map[j][i]);
                map[j][i] = 0;
            }
            int now = N-1;
            while(!q.empty()) {
                int data = q.front();
                q.pop();
                if(map[now][i] == 0) {
                    map[now][i] = data;
                }
                else if(map[now][i] == data) {
                    map[now][i] *= 2;
                    now--;
                }
                else {
                    now--;
                    map[now][i] = data;
                }
            }
        }
    }
}

void dfs(int cnt) {
    if(cnt == 5) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                ans = max(ans, map[i][j]);
            }
        }
        return;
    }

    int copyMap[20][20];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            copyMap[i][j] = map[i][j];
        }
    }

    for(int dir=0; dir<4; dir++) {
        move(dir);
        dfs(cnt+1);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                map[i][j] = copyMap[i][j];
            }
        }       
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0);

    cout << ans;
    return 0;
}