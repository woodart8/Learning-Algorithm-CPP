#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    vector<int> w(v);
    sort(w.begin(),w.end());
    w.erase(unique(w.begin(),w.end()),w.end());
    for(int i=0; i<n; i++){
        auto it = lower_bound(w.begin(),w.end(),v[i]);
        cout<<it-w.begin()<<' ';
    }

    return 0;
}