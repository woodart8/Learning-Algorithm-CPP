#include <iostream>
#include <unordered_map>

using namespace std;

#define MOD 1000000

long long n;
int mem[10]; // 0~9까지의 피보나치 수는 많이 사용되므로 미리 저장
unordered_map<long long, int> m; // 중간 과정에서 사용되는 피보나치 수는 해시테이블 기반의 unordered_map을 사용해 저장

int fibo(long long a) {
     // 캐싱된 값이 있으면 그 값을 사용
    if (a < 10) return mem[a];
    if (m.count(a)) return m[a];

    long long k = a / 2;
    if (a % 2 == 0) {
        // F(2k) = F(k) * [2*F(k+1) − F(k)]
        long long fk = fibo(k);
        long long fk1 = fibo(k + 1);
        m[a] = (int)((fk * ((2 * fk1 % MOD - fk + MOD) % MOD)) % MOD);
    } else {
        // F(2k+1) = F(k+1)^2 + F(k)^2
        long long fk = fibo(k);
        long long fk1 = fibo(k + 1);
        m[a] = (int)((fk1 * fk1 % MOD + fk * fk % MOD) % MOD);
    }

    return m[a];
}

void input() {
    cin >> n;
}

void solve() {
    mem[0] = 0;
    mem[1] = 1;
    for (int i = 2; i < 10; i++) {
        mem[i] = (mem[i - 1] + mem[i - 2]) % MOD;
    }

    cout << fibo(n) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}