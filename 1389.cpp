#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n,m,sum,minIndex,ans=INF;
int map[101][101];

void init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j] = INF;
            if(i==j) map[i][j] = 0;
        }
    }
}

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
            }
        }
    }
}


int main(){
    cin>>n>>m;
    init();
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        map[x][y]=map[y][x]=1;
    }
    floyd();

    for(int i=1; i<=n; i++){
        sum=0;
        for(int j=1; j<=n; j++){
            sum+=map[i][j];
        }
        if(sum<ans){
            ans=sum;
            minIndex = i;
        }
    }

    cout<<minIndex<<'\n';
    return 0;
}