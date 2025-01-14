#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> v1, v2;
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v1.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> v1[i];
    }

    cin >> M;
    v2.resize(M+1);
    for (int i=1; i<=M; i++) {
        cin >> v2[i];
    }

    bool flag = false;
    int last = 1e9;
    int lx = 0;
    int ly = 0;

    while (!flag) {
        int biggest = 0;
        int tx = 0;
        int ty = 0;
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                if (v1[i] == v2[j] && v1[i] > biggest && v1[i] <= last && i > lx && j > ly) {
                    biggest = v1[i];
                    tx = i;
                    ty = j;
                    flag = true;
                }
            }
        }

        if (flag) {
            ans.push_back(biggest);
            last = biggest;
            lx = tx;
            ly = ty;
            flag = false;
        } else {
            break;
        }
    }

    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++) {
        i < ans.size()-1 ? cout << ans[i] << ' ' : cout << ans[i];
    }

    return 0;

}