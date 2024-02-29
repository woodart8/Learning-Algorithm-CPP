#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct SQUARE
{
	int number;
	int len;
	int l;
	int r;
	int c;
};
int sqg(SQUARE a, SQUARE b) {return a.len < b.len;}

int main()
{
	int n;
	while (scanf("%d", &n) > 0) {
		if (n == 0) break;
		int i,j,k;
		vector<SQUARE> sq(n);
		for (i = 0; i < n; i++) {
			int len;
			scanf("%d", &len);
			sq[i].number = i+1;
			sq[i].len = len;
			int maxCenter = len;
			for (j = 0; j < i; j++) {
				int pos;
				if (sq[j].len <= sq[i].len) pos = sq[j].c + 2 * sq[j].len;
				else pos = sq[j].c + 2 * sq[i].len;
				if (maxCenter < pos) maxCenter = pos;
			}
			sq[i].c = maxCenter;
			sq[i].l = maxCenter - len;
			sq[i].r = maxCenter + len;
		}
		sort(sq.begin(), sq.end(), sqg);
		vector<int> res;
		for (i = 0; i < n; i++) {
			double l = sq[i].l;
			double r = sq[i].r;
			for (j = i+1; j < n; j++) {
				if (sq[i].len == sq[j].len) continue;
				if (l < sq[j].r && l >= sq[j].l) l = sq[j].r;
				if (r > sq[j].l && r <= sq[j].r) r = sq[j].l;
			}
			if (l < r) res.push_back(sq[i].number);
		}
		sort(res.begin(), res.end());
		for (i = 0; i <res.size(); i++) {
			if (i) printf(" ");
			printf("%d", res[i]);
		}
		printf("\n");
	}
	return 0;
}