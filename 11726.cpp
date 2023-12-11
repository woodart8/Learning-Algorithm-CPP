#include <iostream>

using namespace std;

int n;
int square[1001];

int main(){
    cin>>n;
    square[1]=1;
    square[2]=2;
    for(int i=3; i<=1000; i++){
        square[i] = (square[i-1]+square[i-2])%10007;
    }

    cout<<square[n]<<'\n';

    return 0;
}