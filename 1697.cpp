#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int time[100001];

int bfs(int x, int y){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now==y){
            return time[now];
        }
        if(now+1<100001){
            if(!visited[now+1]){
                visited[now+1]=true;
                time[now+1]=time[now]+1;
                q.push(now+1);
            }
        }
        if(now-1>=0 && now-1<100001){
            if(!visited[now-1]){
                visited[now-1] = true;
                time[now-1]=time[now]+1;
                q.push(now-1);
            }
        }
        if(2*now<100001){
            if(!visited[2*now]){
                visited[2*now] = true;
                time[2*now]=time[now]+1;
                q.push(2*now);
            }
        }
    }
}

int main(){
    int x,y;
    cin>>x>>y;

    cout<<bfs(x,y)<<'\n';

    return 0;
}