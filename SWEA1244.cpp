#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;
int ans;

void BT(string s, int k) {
    if(k == 0) {
        ans = max(ans, stoi(s));
        return;
    }
    for(int i=0; i<s.size()-1; i++) {
        for(int j=i+1; j<s.size(); j++){
            if(s[i] <= s[j]) {
                swap(s[i],s[j]);
                BT(s,k-1);
                swap(s[i],s[j]);
            }
            if(i == s.size()-2 && j == s.size()-1) {
                swap(s[i],s[j]);
                BT(s,k-1);
                swap(s[i],s[j]);
            }
        }
    }
}

int main() {
    cin >> T;
    int t = 1;
    while(t <= T) {
        ans = 0;
        string s;
        int k;
        cin >> s >> k;
        BT(s,k);
        cout << '#' << t << ' ' << ans << '\n';
        t++;
    }
    return 0;
}