#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v;
    vector<int> ans;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i=n-1; i>=0; i--){
        ans.insert(ans.begin()+v[i],i+1);
    }

    for(auto iter: ans){
        cout<<iter<<' ';
    }

    return 0;
}