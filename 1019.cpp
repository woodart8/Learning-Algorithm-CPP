#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

pair<long long, long long> mem[10];
long long cnt[10];
long long N;

void init() {
    mem[1] = {0, 1};

    for (int i=2; i<=9; i++) {
        long long n1 = mem[i-1].first*10;
        string temp = to_string(mem[i-1].second)+"0";
        temp[0] = i + '0';
        long long n2 = stoll(temp);
        mem[i] = {n1, n2};
        
        for (int j=i-1; j>=1; j--) {
            long long a = j * 9;
            string nine = "";
            for (int k=0; k<i-1-j; k++) {
                if (k == 0) nine += "9";
                else nine += "0";
            }
            if (!nine.empty()) a *= stoll(nine);
            mem[i].first += a;
        }
    }
}

void input() {
    cin >> N;
}

long long check(long long n) {
    if (n < 9) return 1L;

    string s = to_string(n);
    int l = s.size();

    string temp = "";
    for (int i=0; i<l; i++) {
        temp += "9";
        if (n < stoll(temp)) {
            string ret = string(1, s[0]-1); 
            ret += to_string(stoll(temp)/10);
            return stoll(ret);
        }
    }

    return n;
}

void output() {
    for (int i=0; i<=9; i++) {
        i < 9 ? cout << cnt[i] << ' ' : cout << cnt[i];
    }
}

void solve() {
    long long cut = check(N);
    // cout << cut << '\n';

    for (long long i=N; i>cut; i--) {
        long long temp = i;
        while(temp) {
            cnt[temp%10]++;
            temp /= 10;
        }
    }

    string s = to_string(cut);

    if (s[0] == '9') {
        cnt[0] += mem[s.size()].first;
        for (int i=1; i<=9; i++) {
            cnt[i] += mem[s.size()].second;
        }
    } else {
        int front = s[0] - '0';

        long long zero = 0;

        zero += mem[s.size()-1].first*(front+1);
        
        for (int i=s.size()-1; i>=1; i--) {
            long long rest = i*front;
            string nine = "";
            for (int j=0; j<s.size()-1-i; j++) {
                if(j == 0) nine += "9";
                else nine += "0";
            }
            if (!nine.empty()) rest *= stoll(nine);
            zero += rest;
        }

        cnt[0] += zero;

        for (int i=1; i<=9; i++) {
            cnt[i] += mem[s.size()-1].second*(front+1);
        }

        for (int i=1; i<=front; i++) {
            cnt[i] += (int)ceil(pow(10, s.size()-1));
        }
    }
}

int main() {
    init();
    input();
    solve();
    output();
    return 0;
}