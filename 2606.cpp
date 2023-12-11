#include <iostream>

using namespace std;

int n,m;
int count;
bool visit[101];
int map[101][101];

void dfs(int start){
    visit[start] = true;
    if(start != 1){
        count++;
    }
    for(int i=1; i<=n; i++){
        if(visit[i]==false && map[start][i]==1){
            dfs(i);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        map[x][y]=map[y][x]=1;
    }

    dfs(1);
    cout<<count<<'\n';

    return 0;
}