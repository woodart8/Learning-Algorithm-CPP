#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[32001];
int indegree[32001];
int result[32001];
int n;

void topology_sort(){
    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout<<now<<' '; 

        for(int i=0;i<graph[now].size();i++){
            indegree[graph[now][i]]-=1;
            if(indegree[graph[now][i]]==0){
                q.push(graph[now][i]);
            }
        }
    }
}

int main(){
	int m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		indegree[b]+=1;
	}
	
	topology_sort();
	
}