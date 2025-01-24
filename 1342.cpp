#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkValid(string& str) {
    for (int i=0; i<str.size()-1; i++) {
        if (str[i] == str[i+1])
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int ans = 0;

    cin >> s;

    sort(s.begin(), s.end());
    do {
        if (checkValid(s)) ans++;
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << '\n';

    return 0;
}