#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        string s; //명령어
        int n; //숫자 개수
        string t; // 배열
        deque<int> dq; //배열에서 숫자만 빼서 저장
        bool rev = false; //뒤집어져있는지 여부
        bool error = false; //에러발생 여부

        cin >> s >> n >> t;

        string temp = "";
        for(auto c : t) {
            if(isdigit(c)) {
                temp = temp + c;
            }
            else {
                if(!temp.empty()) {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        }

        for(auto c : s) {
            if(c == 'R') rev = !rev;
            else if(c == 'D') {
                if(!dq.empty()) {
                    if(rev == false) {
                        dq.pop_front();
                    }
                    else dq.pop_back();
                }
                else {
                    error = true;
                    break;
                }
            }
        }

        if(!error) {
            cout << '[';
            while(!dq.empty()) {
                if(rev == false) {
                    cout << dq.front();
                    dq.pop_front();
                    if(!dq.empty()) cout << ',';
                }
                else {
                    cout << dq.back();
                    dq.pop_back();
                    if(!dq.empty()) cout << ','; 
                }
            }
            cout << ']' << endl;
        }
        else {
            cout << "error" << endl;
        }
    }
    return 0;
}