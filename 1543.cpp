#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string origin, pattern;
    getline(cin, origin);
    getline(cin, pattern);

    int ans = 0;
    size_t pos = 0;

    while ((pos = origin.find(pattern, pos)) != string::npos) {
        ans++;
        pos += pattern.size();
    }

    cout << ans << '\n';

    return 0;
}