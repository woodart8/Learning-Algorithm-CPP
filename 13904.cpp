#include <iostream>
#include <queue>

using namespace std;

int n;
bool ch[1001];

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second < b.second;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		pq.push({d,w});
	}

	int ans = 0;
	while (!pq.empty()) {
		int day = pq.top().first;
		int point = pq.top().second;
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