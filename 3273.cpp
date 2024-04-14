#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int x;
bool check[2000001];
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> x;

    for(int i=0; i<n; i++) {
        if(v[i]<x && check[x-v[i]]) ans++;
        check[v[i]] = true;
    }

    cout << ans << endl;
    return 0;
}