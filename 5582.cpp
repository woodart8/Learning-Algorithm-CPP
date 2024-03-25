#include <iostream>

using namespace std;

string s;
string t;

int dp[4000][4000];

int main() {
    cin >> s;
    cin >> t;
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<t.size(); j++) {
            if(s[i] == t[j]) dp[i][j] = 1;
        }
    }

    int ans = 0;
    for(int i=1; i<s.size(); i++) {
        for(int j=1; j<t.size(); j++) {
            if(dp[i][j]>0) dp[i][j] = dp[i][j] + dp[i-1][j-1];
            ans = max(dp[i][j], ans); 
        }
    }

    cout << ans << endl;
    return 0;
}