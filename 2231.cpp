#include <iostream>

using namespace std;

int part(int a){
    int sum = a;
    while(a){
        sum+=a%10;
        a/=10;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;

    for(int i=1; i<n; i++){
        int sum = part(i);
        if(sum==n){
            cout<<i<<'\n';
            return 0;
        }
    }

    cout<<0<<'\n';

    return 0;
}