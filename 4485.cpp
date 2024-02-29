#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 99999999
using namespace std;
int n;
int v[130][130];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main()
{
    int cnt = 1;
    while(true){
        cin >> n;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }
        }
        
        priority_queue<pair<int, pair<int,int>>> pq;
        vector <vector <int>> dist(n+1,vector <int>(n+1, INF));
        dist[0][0] = v[0][0];
        pq.push(make_pair(-v[0][0],make_pair(0,0)));
        
        while(!pq.empty()){
            pair<int,pair<int,int>> p = pq.top();
            int cost = -p.first;
            pair<int,int> here = p.second;
            
            pq.pop();
            
            if(cost > dist[here.first][here.second]) continue;
            
            for(int i=0;i<4;i++){
                int nx = here.first + dx[i];
                int ny = here.second + dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    pair<int,int> next = make_pair(nx,ny);
                    int nextcost = v[nx][ny];
                    if (dist[next.first][next.second] > nextcost + cost ){
                        dist[next.first][next.second] = nextcost + cost;
                        pq.push(make_pair(-dist[next.first][next.second], make_pair(next.first, next.second)));
                    }
                }
            }
        }   
        cout << "Problem " << cnt <<": " << dist[n-1][n-1] << "\n";
        cnt++;    
        for(int i=0;i<130;i++){
            memset(v[i], 0, sizeof(int)*130);
        }
    }
}