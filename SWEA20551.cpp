#include <iostream>
#include <vector>

using namespace std;

int T;

int main() {
    cin >> T;
    int t = 1;
    while(t <= T) {
        int ans = 0;
        int num;
        vector<int> v;
        for(int i=0; i<3; i++) {
            cin >> num;
            v.push_back(num);
        }

        if(v[2] < 3 || v[1] < 2) {
            cout << '#' << t << ' ' << -1 << '\n';
            t++;
            continue;
        }

        if(v[1] >= v[2]) {
            int temp = v[1]-v[2]+1;
            v[1] -= temp;
            ans += temp;
        }

        if(v[0] >= v[1]) {
            int temp = v[0]-v[1]+1;
            ans += temp;
        }

        cout << '#' << t << ' ' << ans << '\n';
        t++;
    }
    return 0;
}