#include <iostream>

using namespace std;

int n;
int cnt[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cnt[1]=1;
    cnt[2]=3;
    for(int i=3; i<=n; i++){
        cnt[i]=(cnt[i-1]+2*cnt[i-2])%10007;
    }
    cout<<cnt[n];
}