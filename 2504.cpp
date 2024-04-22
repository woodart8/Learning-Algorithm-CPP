#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int num;
stack<pair<char,int>> S; // 스택에 숫자와 문자 둘다 저장할 수 있도록 pair로 저장

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;

    for(auto c : s) {
        if(c == '(' || c == '[') S.push({c,0}); // ( 또는 [ 면 그냥 push
        if(c == ')') {
            if(S.empty()) break; // 여는 괄호 없는데 닫는 괄호 들어오면 break;
            if(S.top().first == '(') { // () 일 경우 2로 치환
                S.pop();
                S.push({' ', 2});
            }
            else if(S.top().first == ' ') { // (x) 일 경우 x*2로 치환
                num = S.top().second * 2;
                S.pop();
                if(S.empty()) break; // x) 일 경우 break;
                if(S.top().first == '(') S.pop(); 
                else break; // [x), ]x), )x) 일 경우 break;
                S.push({' ', num});
            }
        }
        else if(c == ']') {
            if(S.empty()) break; // 여는 괄호 없는데 닫는 괄호 들어오면 break;
            if(S.top().first == '[') { // [] 일 경우 3으로 치환
                S.pop();
                S.push({' ', 3});
            }
            else if(S.top().first == ' ') { // [x] 일 경우 x*3으로 치환
                num = S.top().second * 3;
                S.pop();
                if(S.empty()) break; // x] 일 경우 break;
                if(S.top().first == '[') S.pop();
                else break; // (x], )x], ]x] 일 경우 break;
                S.push({' ', num});
            }            
        }

        if(!S.empty() && S.top().first == ' ') { // ex: ( 2 9   --->   ( 11 
            int sum = 0;
            while(!S.empty()) {
                if(S.top().first != ' ') break; // 괄호 만나기 전까지 반복
                sum += S.top().second;
                S.pop();
            }
            S.push({' ', sum});
        }
    }

    if(S.empty() || S.size() > 1 || S.top().first != ' ') { //스택에 숫자 1개만 있어야함. 따라서 비어있거나, 2개 이상이거나, 1개지만 숫자가 아닌 경우 0 출력
        cout << 0 << endl;
        return 0;
    }

    cout << S.top().second << endl;
    return 0;
}