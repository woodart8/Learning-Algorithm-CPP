#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

constexpr double e = 2.7182818459045;

int main() {
	fastio;
	int S, P; cin >> S >> P;
	if (S == P) return cout << 1 << '\n', 0;
    if (pow(e, S / e) < P) return cout << -1 << '\n', 0;
	long double prv = -1;
	for (int i = 2; ; i++) {
		long double cur = pow(1.l * S / i, i);
		if (prv > cur) return cout << -1 << '\n', 0;
		if (cur >= P) return cout << i << '\n', 0;
		prv = cur;
	}
}