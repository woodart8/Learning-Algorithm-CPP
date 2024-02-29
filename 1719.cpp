#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

vector<pair<int,int>> graph[1001];
int d[1001];
int prevv[1001];
int n, m;

void dijkstra(int start) {
    fill(d, d+201, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist > d[now]) continue;

        for(int i=0; i<graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if(cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                prevv[graph[now][i].first] = now;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int findAns(int start, int end) {
    while(1) {
        if(prevv[end] == start) return end;
        end = prevv[end];
    }
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	vector<int> num;
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		num.push_back(u);
		num.push_back(v);
		graph[u].push_back({v, cost});
		graph[v].push_back({u, cost});
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	for (int i = 0; i < n; i++) {
		string s = "";
		dijkstra(num[i]);
		for (int j = 0; j < n; j++) {
			if (i == j) {
				s += "- ";
				continue;
			}
			s += to_string(findAns(num[i], num[j])) + " ";
		}
		cout << s << '\n';
	}
	return 0;
}
