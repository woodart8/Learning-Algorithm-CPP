#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int parent[100001];
vector<pair<int,pair<int,int>>> graph;
vector<int> v;
int ans;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    parent[y] = x;
}

bool sameParent(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;   
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        parent[i] = i;
    }

    for(int i=0; i<M; i++) {
        int vil1, vil2, cost;
        cin >> vil1 >> vil2 >> cost;
        graph.push_back({cost,{vil1,vil2}});
    }

    sort(graph.begin(), graph.end());

    for(int i=0; i<graph.size(); i++) {
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        int cost = graph[i].first;
        if(!sameParent(x,y)) {
            merge(x,y);
            v.push_back(cost);
        }
    }

    for(int i=0; i < v.size()-1; i++) {
        ans += v[i];
    }

    cout << ans << '\n';
    return 0;
}