#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool map[31][11];
int N,M,H;
int ans = 1e9;

bool Check() {
    for(int i=1; i<=N; i++) {
        int now = i;
        for(int j=1; j<=H; j++) {
            if(map[j][now]) {
                now++;
            }
            else if(map[j][now-1]){
                now--;
            }
        }
        if(i != now) return false;
    }
    return true;
}

void Solve(int maxDepth, int cnt) {
    if(maxDepth == cnt) {   
        if(Check()) {
            cout << maxDepth << '\n';
            exit(0);
        }
        return;
    }

    for(int j=1; j<N; j++) {
        for(int i=1; i<=H; i++) {
            if(map[i][j] || map[i][j-1] || map[i][j+1]) continue;
            map[i][j] = true;
            Solve(maxDepth, cnt+1);
            map[i][j] = false;
            while(!map[i][j-1] && !map[i][j+1]) i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> H;
    for(int i=1; i<=M; i++) {
        int a,b;
        cin >> a >> b;
        map[a][b] = true;
    }

    for(int i=0; i<=3; i++) {
        Solve(i, 0);
    }
    if(ans == 1e9) cout << -1 << '\n';
    return 0;
}
