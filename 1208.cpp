#include <iostream>
#include <map>
using namespace std;

int num[41];
int n, s;
map<int, int> total;
long long ret = 0;

void leftSum(int st, int sum) {
	if (st == n / 2) {
		total[sum]++;
		return;
	}
	leftSum(st + 1, sum);
	leftSum(st + 1, sum + num[st]);
}

void rightSum(int m, int sum) {
	if (m == n) {
		ret += total[s - sum];
		return;
	}
	rightSum(m + 1, sum);
	rightSum(m + 1, sum + num[m]);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	leftSum(0, 0);
	rightSum(n / 2, 0);
	if (s == 0)
		cout << ret - 1;
	else
		cout << ret;
}