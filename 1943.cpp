#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[50001], n;
int won, cnt;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t = 3;
	
	while (t--) {
		int sum = 0;
		vector <pair<int, int>> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> won >> cnt;
			v.push_back(make_pair(won, cnt));
			sum += won * cnt;
		}

		if (sum % 2 == 1) {
			cout << 0 << endl;
			continue;
		}

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i=0;i<n;i++) {
            for(int j=sum/2;j>=0;j--){
                if(dp[j]) continue;
                int cur=0;
                for(int k=0;k<v[i].second;k++){
                    cur+=v[i].first;
                    if(j-cur>=0)  dp[j]=dp[j-cur];
                }
            }
        }

		if (dp[sum / 2] == 1) {
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;

	}


	return 0;
}