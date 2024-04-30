#include <iostream>

using namespace std;

int z(int n, int r, int c){
    int l = 1<<(n-1);
    int sum = 0;
    while(n>=1) {
        if(n==1){
            sum += 2*r+c;
            return sum;
        }
        if(r<l){
            if(c<l){
                n--;
            }
            else{
                sum += l*l;
                n--;
                c -= l;
            }
        }
        else{
            if(c<l){
                sum += 2*l*l;
                n--;
                r -= l;
            }
            else{
                sum += 3*l*l;
                n--;
                r -= l;                
                c -= l;
            }
        }
        l = l >> 1;
    }
}

int main(){
    int n, r, c;
    cin>>n>>r>>c;
    cout<<z(n,r,c)<<endl;
    return 0;
}