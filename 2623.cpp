#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int N, M;                   
int inDeg[1002] = { 0, };   
vector<int> v[1002];
vector<int> ans;      
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
 
    while (M--) {
        int sNum;
        int s1, s2;
        cin >> sNum;
        if (sNum == 0) continue;
        cin >> s1;
 
        for (int i = 0; i < sNum-1; i++) {
            cin >> s2;
            v[s1].push_back(s2);
            inDeg[s2]++;
            s1 = s2;
        }
    }
 
    queue<int> q;
 
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }
 
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        ans.push_back(s);
 
        for (int i = 0; i < v[s].size(); i++) {
            int next = v[s][i];
            if (--inDeg[next] == 0) {
                q.push(next);
            }
        }
    }
 
    if (ans.size() != N) {
        cout << 0 << endl;
        return 0;
    }
    else {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
