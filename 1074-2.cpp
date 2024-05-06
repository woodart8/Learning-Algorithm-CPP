#include <iostream>

using namespace std;

int npow(int n, int m){
    int r=1;
    for(int i=0;i<m;i++){
        r*=n;
    }
    return r;
}

int z(int n, int r, int c){
    if(n==1){
        return 2*r+c;
    }
    int l=npow(2, n-1);
    if(r<l){
        if(c<l){
            return z(n-1, r, c);
        }
        else{
            return l*l + z(n-1, r, c-l);
        }
    }
    else{
        if(c<l){
            return 2*l*l + z(n-1, r-l, c);
        }
        else{
            return 3*l*l + z(n-1, r-l, c-l);
        }
    }
}

int main(){
    int n, r, c;
    cin>>n>>r>>c;
    cout<<z(n,r,c)<<endl;
    return 0;
}