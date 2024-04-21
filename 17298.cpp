#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
stack<pair<int,int>> s;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    v.resize(N+1);
    for(int i=1; i<=N; i++) {
        int num;
        cin >> num;
        while(!s.empty() && s.top().first < num) {
            v[s.top().second] = num;
            s.pop();
        }
        s.push({num, i});
    }

    while(!s.empty()) {
        v[s.top().second] = -1;
        s.pop();
    }

    for(int i=1; i<=N; i++) {
        cout << v[i] << ' ';
    }
    return 0;
}