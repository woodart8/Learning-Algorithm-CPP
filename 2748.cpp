#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> v(91);
int main() {
    cin >> n;
    v[0] = 0;
    v[1] = 1;
    for(int i=2; i<=n; i++) {
        v[i] = v[i-2]+v[i-1];
    }
    cout << v[n];
}