#include <iostream>
#include <queue>

using namespace std;

int A, B;

int bfs(int a, int b) {
    queue<pair<string,int>> q;
    q.push({to_string(a),0});

    while (!q.empty()) {
        string n = q.front().first;
        int t = q.front().second;
        q.pop();

        int num = stoi(n);
        if (num == b) return t+1;

        if (num <= b/2) {
            string next = to_string(2*num);
            q.push({next, t+1});
        }

        if (num <= b/10) {
            string next = n+"1";
            q.push({next, t+1});
        }
    }

    return -1;
}

void input() {
    cin >> A >> B;
}

void solve() {
    cout << bfs(A, B);
}

int main() {
    input();
    solve();
    return 0;
}