#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int T;
int N;
int arr[502];
int idx[502];

int main() {
    cin >> T;

    while(T--) {
        memset(arr, 0, sizeof(arr));
        memset(idx, 0, sizeof(idx));
        cin >> N;
        int cnt = 0;
        for(int i=1; i<=N; i++) {
            cin >> arr[i];
            idx[arr[i]] = i;
            if(i == arr[i]) cnt++;
        }
		if(cnt == N) {
            cout << 0 << '\n';
            continue;
        }

        int k = N;
        while(idx[k]==k) {
            k--;
        }
        vector<int> ans;
        ans.push_back(idx[k]);
        int box = N+1;
        arr[box] = box;
        idx[box] = box;

		while(cnt < N) {
            swap(arr[idx[box]],arr[idx[k]]);
            swap(idx[box], idx[k]);
            if(idx[k] == k) cnt++;
            if(cnt == N) break;
            k = idx[box];
            if(idx[box] == N+1) {
                while(idx[k]==k) {
                    k--;
                }
            }
            ans.push_back(idx[k]);
        }

        cout << ans.size() << '\n';
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}