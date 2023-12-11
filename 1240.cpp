#include <iostream>
using namespace std;

int d[1001][1001];
bool visited[1001];
int n,m,check;

int findTotal(int x, int y){
    int dist=0;
    visited[x]=true;

    if(d[x][y]!=-1) {
        visited[y]=true;
        check=1;
        return d[x][y];
    }

    for(int i=1; i<=n; i++){
        if(d[x][i] != -1 && visited[i]==false){
            dist = d[x][i];
            dist+=findTotal(i,y);
            if(check==1) break;
        }
    }

    return dist;
}

void clearVisited(){
    check=0;
    for(int i=0; i<1001; i++){
        visited[i] = false;
    }
}

int main(){
    int x,y,dist;

    cin>>n>>m;

    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            d[i][j] = -1;
        }
    }

    for(int i=0; i<n-1; i++){
        cin>>x>>y>>dist;
        d[x][y] = dist;
        d[y][x] = dist;
    }

    for(int i=0; i<m; i++){
        cin>>x>>y;
        clearVisited();
        cout<<findTotal(x,y)<<'\n';
    }

    return 0;
}