#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,c1,c2;
    vector<int> v;
    for(int i=1; i<=3; i++){
        v.push_back(i);
    }
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>c1>>c2;
        for(int j=0; j<3; j++){
            if(v[j]==c1){
                a=j;
            }
            if(v[j]==c2){
                b=j;
            }
        }
        swap(v[a],v[b]);
    }

    cout<<v[0];
    return 0;
}