#include <iostream>

using namespace std;

int d[201][201];

int main(){
    int n, k;
    cin >> n >> k;

    for (int i=0;i<=k;i++)
        d[1][i] = i;
    
    for (int i=2;i<=n;i++)
        for (int j=1;j<=k;j++)
            d[i][j] = (d[i-1][j] + d[i][j-1]) % 1000000000;
        
    cout << d[n][k] << endl;

    return 0;
}