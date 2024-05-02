#include <iostream>

using namespace std;

#define endl '\n'

int N;
char map[64][64];

bool isSameColor(int x, int y, int n, char temp) { // 시작 map[x][y], 한 변의 길이 n, 비교 기준 temp
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(temp != map[i][j]) return false; //기준과 다르면 false
        }
    }
    return true; //모두 동일하면 true
}

void Solve(int x, int y, int n) {
    char temp = map[x][y];
    if(isSameColor(x,y,n,temp)) {
        cout << temp;
    }
    else {
        cout << '(';
        Solve(x, y, n/2);
        Solve(x, y+n/2, n/2);
        Solve(x+n/2, y, n/2) ;
        Solve(x+n/2, y+n/2, n/2);
        cout << ')';
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    Solve(0,0,N);

    return 0;
}