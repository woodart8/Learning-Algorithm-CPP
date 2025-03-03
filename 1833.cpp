#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int dist[200][200];
int parent[200];

int findParent(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]); 
}

void unionNode(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px <= py) parent[py] = px;
    else parent[px] = py;
}

void input() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> dist[i][j];
        }
    }
}

void solve() {
    priority_queue<pair<int, pair<int,int>>> pq;
    vector<pair<int,int>> newPath;
    int totalCost = 0;

    for (int i=0; i<200; i++) {
        parent[i] = i;
    }

    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            if (dist[i][j] > 0) {
                pq.push({-dist[i][j], {i, j}});
            } else if (dist[i][j] < 0) {
                unionNode(i, j);
                totalCost += -dist[i][j];
            }
        }
    }

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();

        if (findParent(cx) != findParent(cy)) {
            unionNode(cx, cy);
            totalCost += cost;
            newPath.push_back({cx,cy});
        }
    }

    cout << totalCost << ' ' << newPath.size() << '\n';
    for (int i=0; i<newPath.size(); i++) {
        cout << newPath[i].first+1 << ' ' << newPath[i].second+1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}