#include <iostream>
#include <vector>

using namespace std;

struct mat {
	int val=1;
	vector<int> edge;
}arr[11];

int vis = 0;

int gcd(int a, int b) {
	return b ? gcd(b,a % b) : a;
}

void update(int node, int mod) {
	arr[node].val *= mod;
	vis |= (1 << node);
	for (auto e : arr[node].edge) {
		if (!(vis & (1 << e))) {
			update(e, mod);
		}
	}
}

int main() {
	int n,a,b,p,q,gcdVal,amod,bmod;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> p >> q;
		gcdVal = gcd(p, q);
		amod = arr[b].val * p / gcdVal;
		bmod = arr[a].val * q / gcdVal;
		gcdVal = gcd(amod, bmod);
		vis = 0;
		update(a, amod/gcdVal);
		update(b, bmod/gcdVal);
		arr[a].edge.push_back(b);
		arr[b].edge.push_back(a);
	}

	for (int i = 0; i < n; i++)
		cout << arr[i].val << " ";
	return 0;
}