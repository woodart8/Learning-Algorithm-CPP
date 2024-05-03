#include <iostream>
#include <cstring>

using namespace std;

int N;
char map[3072][6143];

void Solve(int n, int h, int w) {
    if(n == 3) {
        map[(N-1)-(h+2)][w+2] = '*';
        map[(N-1)-(h+1)][w+1] = map[(N-1)-(h+1)][w+3] = '*';
        for(int i=0; i<5; i++) {
            map[(N-1)-h][w+i] = '*';
        }
        return;
    }
    Solve(n/2, h+n/2, w+n/2);
    Solve(n/2, h, w);
    Solve(n/2, h, w+n);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(map,' ', sizeof(map));
    cin >> N;
    Solve(N, 0, 0);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N*2-1; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }    
    return 0;
}