#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
vector<pair<int,int>> v;
int dp[501][501];
pair<int,int> dp_matrix[501][501];

int Sum(int x, int mid, int y) {
    return dp_matrix[x][mid].first * dp_matrix[x][mid].second * dp_matrix[mid+1][y].second;
}

int main() {
    cin >> N;
    v.resize(N+1,{0,0});
    for(int i=1; i<=N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i=1; i<=N; i++) {
        dp_matrix[i][i] = v[i];
    }

    for(int gap=1; gap<N; gap++) {
        for(int x=1; x+gap<=N; x++) {
            int y = x+gap;
            dp[x][y] = INT32_MAX;
            for(int mid=x; mid<y; mid++) {
                dp[x][y] = min(dp[x][y], dp[x][mid]+dp[mid+1][y]+Sum(x,mid,y));
            }
            dp_matrix[x][y].first = v[x].first;
            dp_matrix[x][y].second = v[y].second;
        }
    }

    cout << dp[1][N] << endl;
    return 0;
}
