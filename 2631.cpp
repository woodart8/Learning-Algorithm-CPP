#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
 

int main() {
	int n; cin >> n; 
	vector <int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i]; 
	}
	int result = 0; 
	vector <int> dp(n + 1, 1); 
	for (int i = 2; i <= n; i++) {
		int max_n=1; 
		for (int j = i - 1; j >= 1; j--) {
			if (v[i] > v[j]) {
				max_n = max(max_n, dp[j] + 1); 
			}
		}
		dp[i] = max_n;
		result = max(result, dp[i]); 
	}
	cout << n - result; 

}