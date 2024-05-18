#include <iostream>
#include <vector>

using namespace std;

int N;
struct Pipe{
    int x1,y1;
    int x2,y2;
    int dir;
};

bool map[17][17];
int ans;

void Input() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }
}

void Solve(Pipe p) {
    if(p.x2 == N && p.y2 == N) {
        ans++;
        return;
    }

    if(p.dir == 0) {
        if(p.y2+1 <= N && !map[p.x2][p.y2+1]) {
            p.y1++; p.y2++;
            Solve(p);
            p.y1--; p.y2--;
            if(p.x2+1 <= N && !map[p.x2+1][p.y2] && !map[p.x2+1][p.y2+1]) {
                p.y1++; p.x2++; p.y2++;
                p.dir = 1;
                Solve(p);
                p.y1--; p.x2--; p.y2--; 
                p.dir = 0;
            }
        }
    }
    else if(p.dir == 1) {
        if(p.y2+1 <= N && !map[p.x2][p.y2+1]) {
            p.x1++; p.y1++; p.y2++;
            p.dir = 0;
            Solve(p);
            p.x1--; p.y1--; p.y2--;
            p.dir = 1;
        }
        if(p.x2+1 <= N && !map[p.x2+1][p.y2]) {
            p.x1++; p.y1++; p.x2++;
            p.dir = 2;
            Solve(p);
            p.x1--; p.y1--; p.x2--;
            p.dir = 1;            
        }
        if(p.x2+1 <= N && p.y2+1 <= N && !map[p.x2+1][p.y2] && !map[p.x2][p.y2+1] && !map[p.x2+1][p.y2+1]) {
            p.x1++; p.y1++; p.x2++; p.y2++;
            Solve(p);
            p.x1--; p.y1--; p.x2--; p.y2--;     
        }
    }
    else {
        if(p.x2+1 <= N && !map[p.x2+1][p.y2]) {
            p.x1++; p.x2++;
            Solve(p);
            p.x1--; p.x2--;
            if(p.y2+1 <= N && !map[p.x2+1][p.y2+1] && !map[p.x2][p.y2+1]) {
                p.x1++; p.x2++; p.y2++;
                p.dir = 1;
                Solve(p);
                p.x1--; p.x2--; p.y2--; 
                p.dir = 2;
            }
        }        
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Input();
    Pipe p;
    p.x1 = 1; p.y1 = 1;
    p.x2 = 1; p.y2 = 2;
    p.dir = 0;
    Solve(p);
    cout << ans << '\n';
    return 0;
}