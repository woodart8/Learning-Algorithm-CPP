#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int N,L,R,s[101][101][101];

int main(){
    cin>>N>>L>>R;
    s[1][1][1]=1;
    f(i,2,N)f(j,1,L)f(k,1,R)
        s[i][j][k]=((ll)s[i-1][j][k]*(i-2)+s[i-1][j][k-1]+s[i-1][j-1][k])%MOD;
    cout<<s[N][L][R];
    return 0;
}