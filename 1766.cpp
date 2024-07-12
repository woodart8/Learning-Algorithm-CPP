#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int cnt[32001];
vector<int> graph[32001];

void topology_sort() {
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=1; i<=N; i++) {
        if(cnt[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();
        cout << now << ' ';

        for(int i=0; i<graph[now].size(); i++) {
            cnt[graph[now][i]]--;
            if(cnt[graph[now][i]] == 0) {
                pq.push(graph[now][i]);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        cnt[b]++;
    }

    topology_sort();

    return 0;
}