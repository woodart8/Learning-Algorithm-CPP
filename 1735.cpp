#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int gcd(int a, int b) {
    if(b > a) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int a, b;
    for(int i=0; i<2; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    a = v[0].first * v[1].second + v[1].first * v[0].second;
    b = v[0].second * v[1].second;

    int n = gcd(a, b);
    cout << a/n << ' ' << b/n << endl;

    return 0;
}