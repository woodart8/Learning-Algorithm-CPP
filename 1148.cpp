#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Word {
    int alpha[26] = {0};
    string s;
};

struct Puzzle {
    int board[26] = {0};
    string s;
};

vector<Word> dict;
vector<Puzzle> trial;
int alpha[26];
int minN = 1e9;
int maxN = 0;

void input() {
    string s;
    while (cin >> s && s != "-") {
        Word w;
        w.s = s;
        for (char c : s) w.alpha[c - 'A']++;
        dict.push_back(w);
    }

    while (cin >> s && s != "#") {
        Puzzle p;
        p.s = s;
        for (char c : s) p.board[c - 'A']++;
        trial.push_back(p);
    }
}

bool checkValid(const Puzzle& p, const Word& w) {
    for (int i = 0; i < w.s.size(); i++) { 
        char cur = w.s[i];
        if (w.alpha[cur - 'A'] > p.board[cur - 'A']) {
            return false;
        }
    }
    return true;
}

void output() {
    for (int i=0; i<26; i++) {
        if (alpha[i] == minN) {
            cout << (char)('A'+i);
        }
    }
    cout << ' ' << minN << ' ';
    for (int i=0; i<26; i++) {
        if (alpha[i] == maxN) {
            cout << (char)('A'+i);
        }
    }
    cout << ' ' << maxN << '\n';
}

void init() {
    minN = 1e9;
    maxN = 0;
    memset(alpha, -1, sizeof(alpha));
}

void solve() {
    for (const auto& p : trial) {
        init();
        for (char c : p.s) {
            int idx = c - 'A';
            int cnt = 0;

            if (alpha[idx] > -1) continue;

            for (const auto& w : dict) {
                if (w.alpha[idx] == 0) continue;
                if (checkValid(p, w)) {
                    cnt++;
                }
            }

            alpha[idx] = cnt;
            minN = min(minN, cnt);
            maxN = max(maxN, cnt);
        }
        output();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}