#include <iostream>

using namespace std;

int num[10];

int main() {
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        if(s[i]-'0' == 9 || s[i]-'0' == 6) {
            if(num[9] > num[6]) num[6]++;
            else num[9]++;
            continue;
        }
        num[s[i]-'0']++;
    }

    int ans = 0;
    for(int i=0; i<=9; i++) {
        ans = max(ans, num[i]);
    }

    cout << ans << endl;
    
    return 0;
}