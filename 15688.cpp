#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    v.resize(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}