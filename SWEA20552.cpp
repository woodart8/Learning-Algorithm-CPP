#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int main() {
    cin >> T;
    while(T--) {
        long long x,s;
        cin >> x >> s;
        if(x > s) {
            cout << -1 << '\n';
            continue;
        }

        if((s-x)%2 == 1) {
            cout << -1 << '\n';
            continue;
        }

        if(s == 0 && x == 0) {
            cout << 0 << '\n';
            continue;
        }

        if(x == s) {
            cout << 1 << '\n';
            cout << x << '\n';
            continue;
        }

        if((x ^ (s-x)/2) + (s-x)/2 == s) {
            cout << 2 << '\n';
            cout << (x ^ (s-x)/2) << ' ' << (s-x)/2 << '\n';
            continue;
        }
        
        cout << 3 << '\n';
        if(x > (s-x)/2) cout << x << ' ' << (s-x)/2 << ' ' << (s-x)/2 << '\n';
        else cout << (s-x)/2 << ' ' << (s-x)/2 << ' ' << x << '\n';
    }
    return 0;
}