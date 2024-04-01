#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> v;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int l = 0;
    int r = v.size()-1;
    int ans = INT32_MAX;
    int ans_l = v[l];
    int ans_r = v[r];

    while(v[l]<v[r]) {
        if(ans > abs(v[l]+v[r])) {
            ans = abs(v[l]+v[r]);
            ans_l = v[l];
            ans_r = v[r];
        }
        if(v[l]+v[r] < 0) {
            l++;
        }
        else if(v[l]+v[r] > 0) {
            r--;
        }
        else break;
    }
    cout << ans_l << ' ' << ans_r << endl;
    return 0;
}