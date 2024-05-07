#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> v;
vector<int> ans(7);

void BT(int k) {
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++) {
        ans[k] = v[i];
        BT(k+1);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int num;
    for(int i=0; i<N; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    BT(0);
    return 0;
}
