#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n,m;
    int sum=0;
    cin>>n>>m;
    string temp;
    string str;
    vector<string> v;
    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
    }

    for(int i=0; i<v.size(); i++){
        str = v[i];
        sum += str.length();
    }

    int q = (m-sum)/(n-1);
    int r = (m-sum)%(n-1);
    string ans = v[0];

    for(int i=1; i<v.size(); i++){
        str = v[i];
        if(str[0]>='a' && str[0]<='z' && r>0){
            ans.append("_");
            r--;
        }

        if(i+r==v.size()){
            ans.append("_");
            r--;
        }

        for(int i=0; i<q; i++){
            ans.append("_");
        }
        ans.append(str); 
    }

    cout<<ans<<'\n';
    return 0;
}