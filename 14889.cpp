#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s[21][21];
int start_p;
int link_p;
int ans = 1e9;
vector<int> start;
vector<int> link;



void backtracking(int depth, int last_idx) {
    if(start.size() > 0) {
        if(start[0] > N/2+1) return;
    }
    if(depth == N/2) {
        start_p = 0;
        link_p = 0;
        for(int i=1; i<=N; i++) {
            if(find(start.begin(), start.end(), i) != start.end()) {
                continue;
            }
            link.push_back(i);
        }

        for(int i=0; i<N/2; i++) {
            for(int j=0; j<N/2; j++) {
                start_p += s[start[i]][start[j]];
                link_p += s[link[i]][link[j]];
            }
        }
        ans = min(ans, abs(start_p-link_p));
        link.clear();
        return;
    }

    for(int i=last_idx+1; i<=N; i++) {
        start.push_back(i);
        backtracking(depth+1, i);
        start.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> s[i][j];
        }
    }

    backtracking(0, 0);

    cout << ans << endl;
    return 0;
}