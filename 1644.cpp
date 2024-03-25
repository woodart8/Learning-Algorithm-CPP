#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> v;
vector<int> prime;

void sosu(int n) {
    for(int i=2; i*i<=n; i++) {
        for(int j=i*i; j<=n; j+=i) {
            v[j] = false;
        }
    }

    for(int i=2; i<=n; i++) {
        if(v[i]) prime.push_back(i);
    }
}

int solve(int n) {
    int start = 0;
    int end = 0;
    int ans = 0;
    int sum = 0;

    while(1) {
        if(sum > n) {
            sum -= prime[start];
            start++;
        }
        else if(sum < n) {
            if(end >= prime.size()) break;
            sum += prime[end];
            end++;
        }
        else {
            ans++;
            if(end >= prime.size()) break;
            sum += prime[end];
            end++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    v.resize(N+1, true);
    sosu(N);
    cout << solve(N) << endl;
	return 0;
}