#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
int id, d[100001];
vector<int> a[100001];
bool finished[100001];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int x) {
	d[x] = ++id;
	s.push(x);
	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int f = s.top();
			s.pop();
			scc.push_back(f);
			finished[f] = true;
			if (f == x) break;
		}
		if (scc.size() > 1) SCC.push_back(scc);
		else if (scc.size() == 1 && a[scc[0]][0] == scc[0]) {
			SCC.push_back(scc);
		}
	}
	return parent;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n ; i++) {
			int c;
			cin >> c;
			a[i].push_back(c);
		}
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) dfs(i);
			cout << d[i] << ' ';
		}
		cout << endl;
		int count = 0;
		for(int i=0;i<SCC.size();i++){
			count += SCC[i].size();
		}
		cout << n - count << "\n";
		memset(d, 0, sizeof(d));
		memset(finished, false, sizeof(finished));
		for (int i = 0; i < SCC.size(); i++) {
			SCC[i].clear();
		}
		SCC.clear();
		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}
		id = 0;
	}
}