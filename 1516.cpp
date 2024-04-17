#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int build[501];
int c[501];
int result[501];
vector<int> graph[501];

void topology_sort() {
    queue<int> q;

    for(int i=1; i<=N; i++) {
        if(build[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];
            result[next] = max(result[next], result[now]+c[next]);
            build[next]--;
            if(build[next] == 0) q.push(next);
        }
    }
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        int num = 0, cost = 0;
        cin >> cost;
        c[i] = cost;
        result[i] = cost;
        while(1) {
            cin >> num;
            if(num == -1) break;
            graph[num].push_back(i);
            build[i]++;
        }
    }

    topology_sort();

    for(int i=1; i<=N; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}