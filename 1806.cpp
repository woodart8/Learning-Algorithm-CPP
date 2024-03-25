#include <iostream>
#include <vector>

using namespace std;

int N,S;
vector<int> v;

int main() {
    cin >> N >> S;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int s=0, e=0, sum=0, minLen = 1e9;
    while(s<=e) {
        if(sum>=S) {
            minLen = min(minLen, e-s);
            sum -= v[s++];
        }
        else if(e == N) break;
        else sum += v[e++];
    }
    if(minLen == 1e9) cout << 0 << endl;
    else cout << minLen << endl;
    return 0;
}