#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
int ans;
int state;
string temp[20];
int map[20][20];
int dp[20][20];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool checkValid(int curState, int alphabet) {
    return curState != (curState | alphabet);
}

int getNextState(int curState, int alphabet) {
    return curState | alphabet;
}

int getPrevState(int curState, int alphabet) {
    return curState ^ alphabet;
}

void dfs(int x, int y, int cnt) {
    if (state == dp[x][y]) return;

    dp[x][y] = state;
    if (ans < cnt) ans = cnt;

	if (0 <= x - 1 && checkValid(state, map[x-1][y])) {
		state = getNextState(state, map[x-1][y]);
		dfs(x - 1, y, cnt + 1);
		state = getPrevState(state, map[x-1][y]);
	}

	if (R > x + 1 && checkValid(state, map[x+1][y])) {
		state = getNextState(state, map[x+1][y]);
		dfs(x + 1, y, cnt + 1);
		state = getPrevState(state, map[x+1][y]);
	}

	if (0 <= y - 1 && checkValid(state, map[x][y-1])) {
		state = getNextState(state, map[x][y-1]);
		dfs(x, y - 1, cnt + 1);
		state = getPrevState(state, map[x][y-1]);
	}

	if (C > y + 1 && checkValid(state, map[x][y+1])) {
		state = getNextState(state, map[x][y+1]);
		dfs(x, y + 1, cnt + 1);
		state = getPrevState(state, map[x][y+1]);
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

	for (int i=0; i<R; i++) {
        cin >> temp[i];
        for (int j=0; j<C; j++)
            map[i][j] = 1 << (temp[i][j]-'A');
    }

    state = getNextState(state, map[0][0]);
    dfs(0,0,1);

    cout << ans << '\n';

    return 0;
}