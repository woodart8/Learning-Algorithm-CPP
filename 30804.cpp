#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans, l, r, fl, fr;
	vector<char> fruit;
	
	cin >> N;
	fruit.resize(N);
	for(auto& e : fruit) cin >> e;
	
	ans = l = -1;
	fl = fr = fruit[0];
	for(r = 0; r < N; r++) {
		if(fruit[r] != fl && fruit[r] != fr) {
			fr = fruit[r];
			fl = fruit[r - 1];
			for(l = r; fruit[l] == fl || fruit[l] == fr; l--);
		}
		if(ans < r - l) ans = r - l;
	}
	cout << ans;
	
	return 0;
}