#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> v;
vector<int> ans(8);

void BT(int k, int idx) {
    if(k == M) {
        for(int i=0; i<M; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int temp = 0;
    for(int i=idx; i<N; i++) {
        if(temp != v[i]) {
            ans[k] = v[i];
            temp = ans[k];
            BT(k+1, i+1);
        }
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

    sort(v.begin(),v.end());
    BT(0, 0);

    return 0;
}