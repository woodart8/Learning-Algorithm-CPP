#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

void input() {
    cin >> N;
    v.resize(N);
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }
}

void solve() {
    if (N == 1) {
        cout << "A" << '\n';
        return;
    }

    if (N == 2) {
        if (v[0] == v[1]) cout << v[0] << '\n';
        else cout << "A" << '\n';
        return;
    }
    
    int a = v[1]-v[0] != 0 ? (v[2]-v[1])/(v[1]-v[0]) : 0;
    int b = v[1] - v[0]*a;
    bool flag = true;

    for (int i=0; i<v.size()-1; i++) {
        if (v[i]*a+b != v[i+1]) {
            flag = false;
            break;
        }
    }

    if (flag) cout << v.back()*a+b << '\n';
    else cout << "B" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}