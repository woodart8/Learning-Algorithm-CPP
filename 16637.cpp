#include <iostream>

using namespace std;

int N;
string s;
int ans = INT32_MIN;

int cal(int a, int b, char op) {
    if(op == '+') return a + b;
    else if(op == '*') return a * b;
    else if(op == '-') return a - b;
}

void dfs(int idx, int sum) {
    if(idx > N-1) {
        ans = max(ans, sum);
        return;
    }

    char op = (idx == 0) ? '+' : s[idx-1];

    if(idx+2 < N) {
        int br = cal(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
        dfs(idx+4, cal(sum, br, op));
    }
    dfs(idx+2, cal(sum, s[idx]-'0', op));
}

int main() {
    cin >> N;
    cin >> s;

    dfs(0, 0);
    cout << ans << endl;
    return 0;
}