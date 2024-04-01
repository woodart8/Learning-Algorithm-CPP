#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,H;
vector<int> v1;
vector<int> v2;
vector<int> v3;
int main() {
    cin >> N >> H;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        if(i%2==0) v1.push_back(num);
        else v2.push_back(num);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int minB = 1e9;
    for(int i=1; i<=H; i++) {
        int num = v1.end() - lower_bound(v1.begin(),v1.end(),i) + 
        v2.end() - lower_bound(v2.begin(), v2.end(), H-i+1);
        v3.push_back(num);
        minB = min(minB, num);
    }

    sort(v3.begin(), v3.end());
    int lo = lower_bound(v3.begin(), v3.end(), minB) - v3.begin();
    int hi = upper_bound(v3.begin(), v3.end(), minB) - v3.begin();
    cout << minB << ' ' << hi-lo << endl;
    return 0;
}