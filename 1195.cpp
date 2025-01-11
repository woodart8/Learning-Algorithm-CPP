#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2;

void input() {
    cin >> s1 >> s2;
}

int getLength() {
    int start = -1;
    int end = static_cast<int>(s2.size())-1;
    bool flag = false;

    while (!flag) {
        flag = true;
        start++;
        end++;
        for (int i=start; i<min(end,static_cast<int>(s1.size())); i++) {
            if (s1[i] == '2' && s2[i-start] == '2') {
                flag = false;
                break;
            }
        }
    }

    return max(end, static_cast<int>(s1.size()));
}

void solve() {
    if (s1.size() < s2.size()) {
        swap(s1,s2);
    }

    int l1, l2;

    l1 = getLength();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    l2 = getLength();

    cout << min(l1, l2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
    return 0;
}