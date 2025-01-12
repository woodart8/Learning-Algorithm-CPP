#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> v;
bool alpha[26];

void input() {
    cin >> N;
    cin.ignore(); // 엔터키 입력된 것 제거
    for (int i=0; i<N; i++) {
        string s;
        getline(cin, s);
        v.push_back(s);
    } 
}

// 단축키 지정 메소드
void changeKeyword(string &s, char c, int idx) {
    int k = tolower(c) - 'a';
    if (!alpha[k]) {
        alpha[k] = true; // 단축키 지정 처리
        s.replace(idx, 1, "[" + string(1, c) + "]"); // 문자열 변경
    }
}

void solve() {
    for (int i=0; i<v.size(); i++) {
        bool flag = false; // 모든 단어의 첫 글자가 단축키인지 판단하는 변수
        for (int j=0; j<v[i].size(); j++) {
            int k = tolower(v[i][j]) - 'a';
            if (alpha[k]) {
                while (v[i][j] != ' ' && j++<v[i].size()) {} // 다음 단어가 나올 때까지 증가
            }
            else {
                changeKeyword(v[i], v[i][j], j);
                flag = true;
                break;
            }
        }

        // 모든 단어의 첫 글자가 이미 단축키이면 나머지 후보 중 가장 왼쪽 것을 단축키로 지정
        if (!flag) {
            for (int j=0; j<v[i].size(); j++) {
                if (v[i][j] == ' ') continue; // 공백은 건너뜀

                int k = tolower(v[i][j]) - 'a';
                if (!alpha[k]) {
                    changeKeyword(v[i], v[i][j], j);
                    break;
                }
            }
        }
        cout << v[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}