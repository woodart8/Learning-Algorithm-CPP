#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {0,0,-1,1}; //세로 이동
int dy[] = {-1,1,0,0}; //가로 이동
char map[13][7]; //맵 배열
bool visited[13][7]; //방문 배열
int ans;

int bfs(int x, int y, char c) { //뿌요 연결 개수 검사하는 함수
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;

    int ret = 1;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || ny < 1 || nx > 12 || ny > 6 || visited[nx][ny] || map[nx][ny] != c) continue;
            visited[nx][ny] = true;
            ret++;
            q.push({nx,ny});
        }
    }
    return ret;
}

void Pang(int x, int y, char c) { // 4개 이상 연결된 뿌요 터뜨리는 함수
    queue<pair<int,int>> q;
    q.push({x,y});
    map[x][y] = '.'; //초기 위치 뿌요 '.'로 변경

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || ny < 1 || nx > 12 || ny > 6 || map[nx][ny] != c) continue;
            map[nx][ny] = '.'; // 연결된 뿌요 '.'로 변경
            q.push({nx,ny});
        }
    }    
}

void Drop() { //뿌요 낙하시키는 함수
    for(int i = 11; i>=1; i--) {
        for(int j=1; j<=6; j++) {
            if(map[i][j] != '.' && map[i+1][j] == '.') { //map[i][j]가 뿌요이고 뿌요 밑이 빈 공간인 경우
                for(int k=1; i+k <= 12; k++) {
                    if(map[i+k][j] != '.') break; // 다른 뿌요와 만나면 break
                    swap(map[i+k-1][j],map[i+k][j]); // 한 칸씩 낙하
                }
            }
        }
    }

    // cout << '\n';
    // for(int x=1; x<=12; x++) {
    //     for(int y=1; y<=6; y++) {
    //         cout << map[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }
}

void Puyo(int cnt) {
    ans = max(ans, cnt); //연쇄 반응 횟수 갱신
    memset(visited,false,sizeof(visited)); //방문 초기화
    bool check = false; // 터진 뿌요 있는지 검사하는 변수
    for(int i=1; i<=12; i++) {
        for(int j=1; j<=6; j++) {
            if(!visited[i][j] && map[i][j] != '.') { //방문한적 없고, 뿌요일 경우
                if(bfs(i,j,map[i][j]) >= 4) { //서로 연결된 뿌요가 4개 이상인 경우
                    Pang(i,j,map[i][j]); //뿌요 터뜨리기
                    check = true; 
                }
            }
        }
    } // 맵 검사

    if(check) { //터진 뿌요 있을 경우
        Drop(); //뿌요 낙하
        Puyo(cnt+1); // 콤보 + 1 하고 다시 연쇄 검사
    }
    return;
}

int main() {
    for(int i=1; i<=12; i++) {
        for(int j=1; j<=6; j++) {
            cin >> map[i][j];
        }
    }

    Puyo(0); // 연쇄 검사
    cout << ans << '\n';

    return 0;
}