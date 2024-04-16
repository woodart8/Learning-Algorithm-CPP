#include <iostream>
#include <queue>

using namespace std;

int n;
bool ch[1001];
struct Hw {
	int day, point;
	bool operator<(const Hw& b) const {
		return point < b.point;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<Hw> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		pq.push({d,w});
	}

	int ans = 0;
	while (!pq.empty()) {
		int day = pq.top().day;
		int point = pq.top().point;
		pq.pop();

		while (ch[day] && day>=1) {
			day--;
		}

		if (day == 0) continue;
		ch[day] = true;
		ans += point;
	}
	cout << ans << '\n';
	return 0;
}