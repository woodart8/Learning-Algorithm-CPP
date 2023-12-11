#include <iostream>

using namespace std;

int coin[10];
int n,k,cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }

    for(int i=n-1; i>=0; i--){
        if(k>=coin[i]){
            cnt+=k/coin[i];
            k%=coin[i];
            if(k==0) break;
        }
    }

    cout<<cnt<<"\n";
    return 0;
}