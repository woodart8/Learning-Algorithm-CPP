#include <iostream>

using namespace std;
#define mod 10007

int dp[1001][10] = {
    0,
};
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {

        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][0] = 1;
                continue;
            }

            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
            dp[i][j] %= mod;
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++)
        result = (result + dp[n][i]);

    cout << result % mod;

    return 0;
}