#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
#define MAX 300

int T,I;
int current_x,current_y,target_x,target_y;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

void bfs(int x,int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(a==target_x && b==target_y) {
            cout <<arr[a][b] << "\n";
            return;
        }
        for(int i=0;i<8;i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if(0<=na && 0<=nb && na <I && nb < I && !visited[na][nb]) {
                q.push({na,nb});
                visited[na][nb]=true;
                arr[na][nb]=arr[a][b]+1;
            }
        }
    }
}

int main() {
    cin >> T;
    for(int i=0;i<T;i++) {
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cin >> I;
        cin >> current_x >> current_y;
        cin >> target_x >> target_y;

        bfs(current_x,current_y);
    }
}