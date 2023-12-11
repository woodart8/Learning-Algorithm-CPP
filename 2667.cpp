#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> vc;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n;
int map[26][26];
int room;
 
void dfs(int i, int j){
      map[i][j] = 0;
      room++;
      for(int k=0;k<4;k++){
            if(i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= n)continue;
            if(map[i + dy[k]][j + dx[k]] == 1)dfs(i + dy[k], j + dx[k]);
      }
}
 
int main(){
      scanf("%d",&n);
 
      for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                  scanf("%1d",&map[i][j]);
 
      for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                  if(map[i][j] == 1){
                        room = 0;
                        dfs(i,j);
                        vc.push_back(room);
                  }
 
      sort(vc.begin(), vc.end());
 
      printf("%d\n",vc.size());
      for(int i=0;i<vc.size();i++)
            printf("%d\n",vc[i]);
 
 
}
