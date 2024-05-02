#include <iostream>

using namespace std;

int N;
bool map[128][128];
int white, blue;

bool checkSameColor(int x, int y, int n, int temp) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(temp != map[i][j]) return false;
        }
    }
    return true;
}

void Solve(int x, int y, int n) {
    bool temp = map[x][y];
    if(!checkSameColor(x,y,n,temp)) {
        Solve(x, y, n/2);
        Solve(x+n/2, y, n/2) ;
        Solve(x, y+n/2, n/2);
        Solve(x+n/2, y+n/2, n/2);
    }
    else {
        if(temp == 0) white++;
        else blue++;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    Solve(0,0,N);
    cout << white << '\n';
    cout << blue << '\n';
    return 0;
}