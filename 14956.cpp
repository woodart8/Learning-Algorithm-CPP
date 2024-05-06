#include <iostream>

using namespace std;

int N, M;

void Solve(int n, int m, int r, int c, int d) {
	if (n == 1) {
        cout << c << ' ' << r << endl;
        return;
    }

	n /= 2;
	int area = n * n;

	if (d == 0) {
		if (1 <= m && m <= area) return Solve(n, m, r, c, 1);
		else if (area < m && m <= 2 * area) return Solve(n, m - area, r + n, c, 0);
		else if (2 * area < m && m <= 3 * area) return Solve(n, m - 2 * area, r + n, c + n, 0);
		return Solve(n, m - 3 * area, r + n - 1, c + 2 * n - 1, 3);
	}
	else if (d == 1) {
		if (1 <= m && m <= area) return Solve(n, m, r, c, 0);
		else if (area < m && m <= 2 * area) return Solve(n, m - area, r, c + n, 1);
		else if (2 * area < m && m <= 3 * area) return Solve(n, m - 2 * area, r + n, c + n, 1);
		return Solve(n, m - 3 * area, r + 2 * n - 1, c + n - 1, 2);
	}
	else if (d == 2) {
		if (1 <= m && m <= area) return Solve(n, m, r, c, 3);
		else if (area < m && m <= 2 * area) return Solve(n, m - area, r - n, c, 2);
		else if (2 * area < m && m <= 3 * area) return Solve(n, m - 2 * area, r - n, c - n, 2);
		return Solve(n, m - 3 * area, r - n + 1, c - 2 * n + 1, 1);
	}
    
	if (1 <= m && m <= area) return Solve(n, m, r, c, 2);
	else if (area < m && m <= 2 * area) return Solve(n, m - area, r, c - n, 3);
	else if (2 * area < m && m <= 3 * area) return Solve(n, m - 2 * area, r - n, c - n, 3);
	return Solve(n, m - 3 * area, r - 2 * n + 1, c - n + 1, 0);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	Solve(N, M, 1, 1, 0);

	return 0;
}