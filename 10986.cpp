#include <iostream>
// BOJ - 10986 Remainder Summation
using namespace std;

long long mod[1001];

int main(void) {
	int n, m, t;
	long long psum = 0, cnt = 0;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
    //(3~4 psum)%mod는 (1~4 psum - 1~2 psum)%mod --> 1~4psum%mod = 1~2psum%mod
	for (int i = 1; i <= n; i++) {
		cin >> t;
		psum += t;
		mod[psum % m]++;
	}

	for (int i = 0; i <= m; i++) 
		cnt += ((mod[i] * (mod[i] - 1)) / 2);

	cout << mod[0] + cnt;

	return 0;
}