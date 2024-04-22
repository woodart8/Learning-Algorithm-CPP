#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int ans;

int main() {
    string s;
    cin >> s;
    char bef = ' '; // 이전에 나온 괄호 모양 저장
    int cnt = 0;

    for(auto c : s) {
        if(c == '(') {
            if(bef == '(') {
                cnt++;
            }
            bef = '(';
        }
        else {
            if(bef == '(') {
                ans += cnt;
            }
            else {
                ans++;
                cnt--;
            }
            bef = ')';
        }
    }

    cout << ans << endl;
    return 0;
}