#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cal[4]; //+ - * /
vector<int> num;
vector<int> ans;

void dfs(int depth, int sum) {
    if(depth == N) {
        ans.push_back(sum);
        return;
    }

    for(int i=0; i<4; i++) {
        if(cal[i] > 0) {
            cal[i]--;
            switch (i) {
                case 0:
                    dfs(depth+1, sum+num[depth]);
                    break;
                case 1:
                    dfs(depth+1, sum-num[depth]);
                    break;
                case 2:
                    dfs(depth+1, sum*num[depth]);
                    break;
                case 3:
                    dfs(depth+1, sum/num[depth]);
                    break;
            }
            cal[i]++;
        }
    }
}

int main() {
    cin >> N;
    int A;
    for(int i=0; i<N; i++) {
        cin >> A;
        num.push_back(A);
    }
    for(int i=0; i<4; i++) {
        cin >> cal[i];
    }

    dfs(1, num[0]);
    sort(ans.begin(), ans.end());
    cout << ans[ans.size()-1] << endl;
    cout << ans[0] << endl;
    return 0;
}

