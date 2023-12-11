#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,temp;
    bool sosu[1001] = {false};
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
    }

    sosu[0] = true;
    sosu[1] = true;
    for(int i=2; i<=500; i++){
        for(int j=2*i; j<=1000; j+=i){
            sosu[j]= true;
        }
    }

    int count = 0;
    for(auto iter: v){
        if(sosu[iter] == false){
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}