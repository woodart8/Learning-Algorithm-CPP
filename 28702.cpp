#include <iostream>
#include <string>

using namespace std;

string s[3];
int n;
string ans;

void input() {
    for (int i=0; i<3; i++) {
        cin >> s[i];
        if (isdigit(s[i][0])) n = stoi(s[i]) + 3 - i;
    }
}

void solve() {
    if (n % 3 == 0 && n % 5 == 0) {
        ans = "FizzBuzz";
    }
    else if (n % 3 == 0) {
        ans = "Fizz";
    }
    else if (n % 5 == 0) {
        ans = "Buzz";
    }
    else {
        ans = to_string(n);
    }
}

void output() {
    cout << ans << '\n'; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
    output();
    return 0;
}