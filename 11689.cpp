#include <iostream>
#include <vector>

using namespace std;

long long n;

// 오일러 피 함수 (Euler's Totient Function) 계산 함수
long long eulerPhi(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            // p는 n의 소인수
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }
    // 마지막 남은 소수 처리
    if (n > 1) {
        result -= result / n;
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cout << eulerPhi(n) << '\n';
    return 0;
}