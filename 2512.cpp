#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> v;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> M;
    
    sort(v.begin(), v.end());

    int l = 0;
    int r = v[v.size()-1];
    int ans = 0;
    while(l<=r) {
        int sum = 0;
        int mid = (l+r)/2;
        for(int i=0; i<v.size(); i++) {
            if(v[i]>=mid) sum += mid;
            else sum += v[i];
        }
        if(sum > M) {
            r = mid-1;
        }
        else {
            ans = max(ans, mid);
            l = mid+1;
        }
    }

    cout << ans << endl;
    return 0;
}