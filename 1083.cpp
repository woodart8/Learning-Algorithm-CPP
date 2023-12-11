#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,tmp,count;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    
    cin>>count;

    if(count>=n*(n-1)/2){
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(auto iter: v){
            cout<<iter<<' ';
        }
        return 0;
    }

    int l=0, m=0;

    while(count){
        int max=0, maxl=0;
        while(l<v.size() && l-m<=count){
            if(max<v[l]){
                max = v[l];
                maxl = l;
            }
            l++;
        }
        v.erase(v.begin()+maxl);
        v.insert(v.begin()+m, max);
        count = count-(maxl-m);
        m++;
        l=m;
        if(l==v.size()) count=0;
    }

    for(auto iter: v){
        cout<<iter<<' ';
    }
    return 0;
}