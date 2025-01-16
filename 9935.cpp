#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string s,t;
stack<char> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
        st.push(s[i]);

        if (st.size() >= t.size()) {
            string temp = "";
            for (int j=0; j<t.size(); j++) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp.compare(t) != 0) {
                for (int k=0; k<temp.size(); k++) {
                    st.push(temp[k]);
                }
            }
        }
    }

    if (!st.empty()) {
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    else {
        cout << "FRULA";
    }

    return 0;
}