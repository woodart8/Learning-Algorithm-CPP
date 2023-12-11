#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        if(a.second<=b.second){
            return 1;
        }
        else return 0;
    }
    else{
        return a.first<=b.first;
    }
}

int main(){
    vector<pair<int,int>> v;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        pair<int,int> p;
        cin>>p.first>>p.second;
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);

    for(auto iter: v){
        cout<<iter.first<<' '<<iter.second<<'\n';
    }
    return 0;
}