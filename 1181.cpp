#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sizeCompare(const string &a, const string &b){
    if(a.size() < b.size())
        return true;
    else
        return false;
}

int main(){
    int n;
    string str;
    vector<string> v;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>str;
        v.push_back(str);
    }

    sort(v.begin(),v.end());

    v.erase(unique(v.begin(),v.end()),v.end());

    stable_sort(v.begin(),v.end(),sizeCompare);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    return 0;
}