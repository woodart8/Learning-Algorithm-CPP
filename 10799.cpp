#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<char> S;
int ans;

int main() {
    string s;
    cin >> s;
    int cnt = 0; //현재까지 막대 몇개 나왔는지 계산하는 변수
    S.push(' ');
    
    for(auto c : s) {
        if(c == '(') {
            if(S.top() == '(') {
                cnt++;
            }
        }
        else {
            if(S.top() == '(') {
                ans += cnt;
            }
            else {
                ans++;
                cnt--;
            }
        }
        S.push(c);
    }

    cout << ans << endl;
    return 0;
}