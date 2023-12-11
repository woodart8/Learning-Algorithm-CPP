#include <iostream>
typedef unsigned long long ull;
using namespace std;


ull r(int a, int b, int c){
    if(b==1) return (ull)a%c;

    ull k = r(a,b/2,c)%c;
    if(b%2==0) return k*k%c;
    else return k*k%c*a%c;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    
    cout<<r(a,b,c)<<'\n';

    return 0;
}