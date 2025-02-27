#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,T;
string dp[101][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int i=2; i<=100; i++) {
        string s = "";
        i%2 ? s+="7" : s+="1";

        for (int j=1; j<i/2; j++)
            s += "1";

        dp[i][1] = s;
    }

    dp[2][0] = "1";
    dp[3][0] = "7";
    dp[4][0] = "4";
    dp[5][0] = "2";
    dp[6][0] = "6";
    dp[7][0] = "8";

    for (int i=8; i<=100; i++) {
        vector<long long> temp;
        for (int j=2; j<=i-2; j++) {
            string s = dp[j][0] + dp[i-j][0];
            for (int k=1; k<s.size(); k++) {
                if (s[k] == '6') {
                    s[k] = '0';
                }
            }
            temp.push_back(stoll(s));
        }
        sort(temp.begin(), temp.end());
        dp[i][0] = to_string(temp[0]);
    }

    while(T--) {
        cin >> N;
        cout << dp[N][0] << ' ' << dp[N][1] << '\n';
    }
    return 0;
}