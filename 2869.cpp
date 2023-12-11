#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,v;
    cin>>a>>b>>v;

    if((v-b)%(a-b)!=0){
        cout<<(v-b)/(a-b)+1<<'\n';
    }
    else cout<<(v-b)/(a-b)<<'\n';

    return 0;
}