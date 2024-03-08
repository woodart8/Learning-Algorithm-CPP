#include <iostream>
#include <vector>

#define mod 1000000000
using namespace std;

int dp[101][10] = {
    0,
};
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= mod;
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result = (result + dp[n][i]) % mod;
    }
    cout << result << "\n";

    return 0;
}