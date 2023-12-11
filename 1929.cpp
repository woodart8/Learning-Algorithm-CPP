#include <iostream>
#include <cmath>
using namespace std;

int sosu[1000001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int m,n;
    cin>>m>>n;
    sosu[1]=1;

    for(int i=2; i<=sqrt(n); i++){
        if(sosu[i]==1) continue;
        for(int j=i*i; j<=n; j+=i){
            if(sosu[j]==1) continue;
            sosu[j]=1;
        }
    }
    
    for(int i=m; i<=n; i++){
        if(sosu[i]==0){
            cout<<i<<'\n';
        }
    }

    return 0;
}