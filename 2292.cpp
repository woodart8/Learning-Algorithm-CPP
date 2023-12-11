#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n;

    int minl=1, maxl=1;
    if(n==1){
        cout<<1<<'\n';
        return 0;
    }
    else{
        for(k=2; n>7+(k-2)*(24+6*(k-3))/2;k++){}
        cout<<k<<'\n';
    }

    return 0;
}