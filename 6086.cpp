#include <iostream>
#include <vector>
#include <queue>

#define MAX 53
#define INF 1e9

using namespace std;

int N, result;
vector<int> graph[MAX];
int c[MAX][MAX], f[MAX][MAX], d[MAX];

int ctoi(char a) {
    if(a>='A' && a<='Z') return a-'A'+1;
    else if(a>='a' && a<='z') return a-'a'+27;
}

void maxFlow(int start, int end) {
    while(1) {
        fill(d, d+MAX, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int i=0; i<graph[x].size(); i++) {
                int y = graph[x][i];
                if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x;
                    if(y == end) break;
                }
            }
        }
        if(d[end] == -1) break;
        int flow = INF;
        for(int i=end; i!=start; i=d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        for(int i=end; i!=start; i=d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }
        result += flow;
    }
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        char start, end;
        int capacity;
        cin >> start >> end >> capacity;
        int start_node = ctoi(start);
        int end_node = ctoi(end);
        graph[start_node].push_back(end_node);
        graph[end_node].push_back(start_node);
        c[start_node][end_node] += capacity;
        c[end_node][start_node] += capacity;
    }

    maxFlow(1,26);
    printf("%d", result);
}