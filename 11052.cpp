#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> menu;

int dp[1001];

int main() {
    cin >> N;
    int price;
    for(int i=0; i<N; i++) {
        cin >> price;
        menu.push_back(price);
    }

    dp[1] = menu[0];
    for(int i=2; i<=N; i++) {
        for(int j=i; j>=i/2; j--) {
            if(j == i) dp[j] = menu[j-1];
            if(dp[j] + dp[i-j] > dp[i]) dp[i] = dp[j] + dp[i-j];
        }
    }

    cout << dp[N] << endl;

    return 0;
}