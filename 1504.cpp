#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int n,e,a,b,c;
vector<pair<int,int>> Edge[801];
int dist[801];
priority_queue<pair<int,int>> q;

void dijkstra(int start){
    dist[start]=0;
    q.push(make_pair(0,start));
    while(!q.empty()){
        int d = -q.top().first;
        int now = q.top().second;
        q.pop();

        if(dist[now]<d){
            continue;
        }

        for(int i=0; i<Edge[now].size(); i++)
        {
            int cost = d+Edge[now][i].second;
            if(cost<dist[Edge[now][i].first]){
                dist[Edge[now][i].first]=cost;
                q.push(make_pair(-cost,Edge[now][i].first));
            }
        }
    }    
}

void init(int n){
    fill(dist,dist+n,INF);
}
int main(){
    cin>>n>>e;
    init(n);
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        Edge[a].push_back(make_pair(b,c));
        Edge[b].push_back(make_pair(a,c));
    }

    int v1, v2;
    cin>>v1>>v2;

    int temp[6];

    dijkstra(1);
    temp[0]=dist[v1];
    temp[1]=dist[v2];
    init(n);

    dijkstra(v1);
    temp[2]=dist[v2];
    temp[4]=dist[n];
    init(n);

    dijkstra(v2);
    temp[3]=dist[v1];
    temp[5]=dist[n];
    
    int res1,res2;
    if(temp[0]==INF||temp[2]==INF||temp[5]==INF){
        res1 = INF;
    }
    else{
        res1 = temp[0]+temp[2]+temp[5];
    }
    if(temp[1]==INF||temp[3]==INF||temp[4]==INF){
        res2 = INF;
    }
    else{
        res2 = temp[1]+temp[3]+temp[4];
    }

    if(res1==INF&&res2==INF){
        cout<<-1<<'\n';
    }
    else cout<<min(res1,res2)<<'\n';

    return 0;
}