#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int N; cin >> N;
	string Mu(50001, 0); Mu[1] = 1;
	for (int i = 1; i <= 50000; i++) {
		for (int j = 2 * i; j <= 50000; j += i) Mu[j] -= Mu[i];
		Mu[i] += Mu[i - 1];
	}
	while (N--) {
		int a, b, d, res = 0; cin >> a >> b >> d;
		if (a > b) swap(a, b); a /= d, b /= d;
		for (int ia = 1, ja; ia <= a; ia = ja + 1) {
			ja = min(a / (a / ia), a);
			for (int ib = ia, jb; ib <= ja; ib = jb + 1) {
				jb = min(b / (b / ib), ja);
				res += (Mu[jb] - Mu[ib - 1]) * (a / ib) * (b / ib);
			}
		}
		cout << res << '\n';
	}
}