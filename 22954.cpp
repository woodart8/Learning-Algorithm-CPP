#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M;
int parent[100001], ran[100001];
vector<pair<int,int>> v[100001];
bool visited[100001];
int connect[100001];
vector<int> t1, te1, t2, te2;

int findParent(int a) {
    if (parent[a] != a) parent[a] = findParent(parent[a]);
    return parent[a];
}

void unionNode(int a, int b) {
    int pa = findParent(a), pb = findParent(b);
    if (pa == pb) return;
    if (ran[pa] > ran[pb]) {
        parent[pb] = pa;
    } else if (ran[pa] < ran[pb]) {
        parent[pa] = pb;
    } else {
        parent[pb] = pa;
        ran[pa]++;
    }
}

void dfs(int a, bool flag) {
    vector<int>& nodes = flag ? t1 : t2;
    vector<int>& edges = flag ? te1 : te2;

    nodes.push_back(a);
    visited[a] = true;

    for (pair<int, int>& p : v[a]) {
        if (visited[p.first]) continue;
        edges.push_back(p.second);
        dfs(p.first, flag);
    }
}

void printResult() {
    auto printVector = [](const vector<int>& vec) {
        for (int x : vec) cout << x << ' ';
        cout << '\n';
    };
    
    cout << t1.size() << ' ' << t2.size() << '\n';
    printVector(t1);
    printVector(te1);
    printVector(t2);
    printVector(te2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        parent[i] = i;
    }

    for (int i=1; i<=M; i++) {
        int a, b;
        cin >> a >> b;
        if (findParent(a) != findParent(b)) {
            unionNode(a, b);
            v[a].push_back({b, i});
            v[b].push_back({a, i});
            connect[a]++;
            connect[b]++;
        }
    }

    // 정점이 2개 이하면 2개의 서로 다른 크기를 가진 트리로 분해할 수 없음
    if (N <= 2) {
        cout << -1 << '\n';
        return 0;
    }

    // 트리 개수를 계산하는 로직
    unordered_map<int, int> m; 
    for (int i=1; i<=N; i++) {
        m[findParent(i)]++;
    }

    if (m.size() >= 3) {
        cout << -1 << '\n';
        return 0;
    } // 트리가 3개 이상이면 2개로 만들수 없음
    else if (m.size() == 2) {
        auto it = m.begin();
        int k1 = it -> first;
        int v1 = it -> second;
        
        ++it;
        int k2 = it -> first;
        int v2 = it -> second;

        if (v1 == v2) {
            cout << -1 << '\n';
            return 0;
        }
        dfs(k1, true);
        dfs(k2, false);
    } // 트리가 2개일 경우 두 트리의 크기가 같으면 불가, 다르면 가능
    else {
        int leaf = -1;
        for (int i=1; i<=N; i++) {
            if (connect[i] == 1) {
                leaf = i;
                break;
            }
        }

        int dest = v[leaf][0].first;
        v[dest].erase(remove_if(v[dest].begin(), v[dest].end(), [&](pair<int, int>& p) { return p.first == leaf; }), v[dest].end());
        v[leaf].clear();

        dfs(leaf, true);
        dfs(dest, false);
    } // 정점의 개수 > 2 이므로 트리가 1개일 경우 리프 노드 하나를 잘라내면 서로 다른 크기의 트리 2개가 완성된다.  

    printResult();
    
    return 0;
}