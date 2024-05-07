#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> v(7); 

void BT(int n) {
    if(n == M) {
        for(int i=0; i<M; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++) {
        v[n] = i;
        BT(n+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    BT(0);
}