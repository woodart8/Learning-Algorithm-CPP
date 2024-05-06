#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> map[21];
bool bishop[21];
int ans[2];


void BT(int idx, int n, int color) {
    if(idx > 2*N) {
        ans[color] = max(ans[color], n);
        return;
    }
    for(int i=0; i<map[idx].size(); i++) {
        int x = map[idx][i].first;
        int y = map[idx][i].second;
        if(!bishop[N-x+y]) {
            bishop[N-x+y] = true;
            BT(idx+2, n+1, color);
            bishop[N-x+y] = false;
        }
    }
    BT(idx+2, n, color);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    int num;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> num;
            if(num == 1) map[i+j].push_back({i,j});
        }
    }

    BT(2,0,0);
    BT(3,0,1);
    cout << ans[0]+ans[1] << endl;
    return 0;
}