#include <iostream>
#include <queue>

#define MAX 1001
using namespace std;

int T,N,K,W;
vector<int> cost;
vector<int> result;
vector<int> graph[MAX];
int indegree[MAX];

void topology_sort() {
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(i==W) continue;
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<graph[x].size(); i++) {
            int y = graph[x][i];
            result[y] = max(result[y], result[x]+cost[y]);
            if(--indegree[y]==0) q.push(y);
        }
    }
}

int main(){
    cin >> T;
    while(T) {
        cin >> N >> K;
        cost.resize(N+1,0);
        result.resize(N+1,0);
        for(int i=1; i<=N; i++) {
            cin >> cost[i];
            result[i] = cost[i];
        }
        for(int i=1; i<=K; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }
        cin >> W;
        topology_sort();
        cout << result[W] << endl;
        for(int j=1; j<=N; j++) {
            indegree[j] = 0;
            result.clear();
            cost.clear();
            graph[j].clear();
        }
        T--;
    }
    return 0;
}