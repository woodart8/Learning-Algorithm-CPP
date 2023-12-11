#include <iostream>

using namespace std;

int main(){
    int n,k,t;
    int nf=1,kf=1,tf=1;
    cin>>n>>k;
    t = n-k;

    if(k<0) cout<<0<<'\n';
    else if(k>n) cout<<0<<'\n';
    else{
        for(int i=1; i<=n; i++){
            nf *= i;
        }
        for(int i=1; i<=k; i++){
            kf *= i;
        }
        for(int i=1; i<=t; i++){
            tf *= i;
        }

        cout<<nf/(kf*tf)<<'\n';
    }

    return 0;
}