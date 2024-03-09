#include <iostream>
#include <cstring>
using namespace std;
#define INF 1e9

int N;
int dist[16][16];
int memo[16][1 << 16];

int tsp(int pos, int mask) {
    if (mask == (1 << N) - 1) {
        if(dist[pos][0] == 0) return INF;
        return dist[pos][0];
    }
    if (memo[pos][mask] != -1) return memo[pos][mask];
    int ans = INF;
    for (int i = 0; i < N; i++) {
        if (i == pos || (mask & (1 << i)) || dist[pos][i] == 0) continue;
        ans = min(ans, dist[pos][i] + tsp(i, mask | (1 << i)));
    }
    return memo[pos][mask] = ans;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> dist[i][j];
        }
    }

    memset(memo, -1, sizeof(memo));
    int best = INF;
    best = min(best, tsp(0, 1));
    cout << best << endl;

    return 0;
}