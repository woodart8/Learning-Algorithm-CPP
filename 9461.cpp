#include <iostream>
#include <vector>
using namespace std;

long long len[101];
int t,n;
vector<long long> v;

int main(){
    cin>>t;
    len[1]=1;
    len[2]=1;
    len[3]=1;
    len[4]=2;
    for(int i=5; i<=100; i++){
        len[i]=len[i-1]+len[i-5];
    }
    while(t--){
        cin>>n;
        v.push_back(len[n]);
    }

    for(auto it: v){
        cout<<it<<'\n';
    }

    return 0;
}
