#include <iostream>

using namespace std;

int N;
bool map[128][128];
int white, blue;

bool isSameColor(int x, int y, int n, int temp) { // 시작 map[x][y], 한 변의 길이 n, 비교 기준 temp
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(temp != map[i][j]) return false; //기준과 다르면 false
        }
    }
    return true; //모두 동일하면 true
}

void Solve(int x, int y, int n) { // 시작 map[x][y], 한 변의 길이 n
    bool temp = map[x][y];
    if(!isSameColor(x,y,n,temp)) { // 색이 다른게 있으면 4등분
        Solve(x, y, n/2);
        Solve(x+n/2, y, n/2) ;
        Solve(x, y+n/2, n/2);
        Solve(x+n/2, y+n/2, n/2);
    }
    else { // 모두 색이 동일하면 종이 색에 따라서 (color)++
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