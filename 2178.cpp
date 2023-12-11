#include <iostream>
#include <queue>

using namespace std;

int n,m;
int map[101][101];
int cnt[101][101];
bool visited[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int>> q;

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        for(int j=1; j<=m; j++){
            map[i][j]  = s[j-1]-'0';
        }
    }

    visited[1][1] = true;
    q.push(make_pair(1,1));
    cnt[1][1] = 1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int tmpx = x+dx[i];
            int tmpy = y+dy[i];
            
            if((0<tmpy&&tmpy<=n)&&(0<tmpx&&tmpx<=m)&&
            map[tmpy][tmpx]==1 && !visited[tmpy][tmpx]){
                visited[tmpy][tmpx]=true;
                q.push(make_pair(tmpy,tmpx));
                cnt[tmpy][tmpx]=cnt[y][x]+1;  
            }
        } 
    }

    cout<<cnt[n][m]<<'\n';
    return 0;
}