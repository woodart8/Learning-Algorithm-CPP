#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(temp==0){
            v.pop_back();
        }
        else{
            v.push_back(temp);
        }
    }

    int sum=0;
    for(auto it: v){
        sum+=it;
    }
    cout<<sum<<"\n";
    return 0;
}