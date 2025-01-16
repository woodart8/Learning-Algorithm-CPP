#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int n, k;
pair<int, int> dp[MAX];

void init(){
    for(int i = 0; i < MAX; i++){
        dp[i] = {-1, 0};
    }
    dp[n] = {0, 1};
}

void bfs(){
    queue<pair<int, int>> q;
    q.push({0, n});

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        if (dp[k].second && dp[k].first < p.first) break;

        int pos[] = {p.second - 1, p.second + 1, 2 * p.second};

        for (auto i : pos) {
            if (i < 0 || i >= MAX) continue;

            if (dp[i].first == -1){
                dp[i] = {p.first + 1, dp[p.second].second};
                q.push({p.first + 1, i});
            }
            else if (dp[i].first == p.first + 1){
                dp[i].second += dp[p.second].second;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    init();

    if (n != k) bfs();

    cout << dp[k].first << "\n" << dp[k].second;

    return 0;
}