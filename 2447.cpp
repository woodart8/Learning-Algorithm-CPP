#include <iostream>
#include <cstring>

using namespace std;

int N;
char map[6561][6561];

void Solve(int x, int y, int n) {
    if(n == 1) {
        map[x][y] = '*';
        return;
    }
    Solve(x, y, n/3);
    Solve(x, y+n/3, n/3);
    Solve(x, y+n/3*2, n/3);
    Solve(x+n/3, y, n/3);

    Solve(x+n/3, y+n/3*2, n/3);
    Solve(x+n/3*2, y, n/3);
    Solve(x+n/3*2, y+n/3, n/3);
    Solve(x+n/3*2, y+n/3*2, n/3);
}

int main() {
    cin >> N;
    memset(map, ' ', sizeof(map)); 
    Solve(0,0,N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}