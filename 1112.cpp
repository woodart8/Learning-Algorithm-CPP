#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int x,b;

int customMod(int a, int b) {
    // 나머지는 무조건 b보다 작고 0과 같거나 보다 커야함
    return ((a % b) + abs(b)) % abs(b);
}

string changeTenToK(int num, int k) {
    if (num == 0) return "0";

    string s = "";
    bool flag = false;

    if (num < 0 && k > 0) flag = true;
    if (k > 0) num = abs(num);
    // (num : -12, k : 10) -> -1 x 10^1 + -2 + 10^0 이므로 
    // -1 -2 이런식으로 나오기 때문에 절댓값으로 1 2 구해주고 앞에 "-" 붙이기 

    while (num) {
        int r = customMod(num, k);
        s += to_string(r);
        num = (num - r) / k;
        // num = k * q + r
        // q = (num - r) / k 
        // 그냥 num / k로 하면 num이 음수일 때 문제가 발생
    }

    if (flag) s += "-";

    reverse(s.begin(), s.end());
    return s;
}

void input() {
    cin >> x >> b;
}

void solve() {
    cout << changeTenToK(x, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}