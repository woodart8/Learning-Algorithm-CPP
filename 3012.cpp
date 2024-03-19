#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const long long MOD = 100000;
const int MAX = 200;
int N;
string s;
long long cache[MAX][MAX];
string open = "({[", close = ")}]";

long long func(int start, int end){
    if (start > end) return 1;
    long long &result = cache[start][end];
    if (result != -1) return result;
    result = 0;
    for (int i = start + 1; i <= end; i += 2) {
        for(int j=0; j<open.size(); j++) {
            if(s[start] == open[j] || s[start] == '?') {
                if (s[i] == close[j] || s[i] == '?'){
                    long long temp = func(start + 1, i - 1) * func(i + 1, end);
                    result += temp;
                    if (result >= MOD) result = MOD + result % MOD;
                }
            }
        }
    }
    return result;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> s;
    memset(cache, -1, sizeof(cache));
    long long result = func(0, N - 1);
    if (result >= MOD) printf("%05lld\n", result%MOD);
    else cout << result << "\n";
    return 0;
}