#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

stack<int> s;

int main(){
    int n,temp,j=1,check = 0;
    vector<string> ans;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(check==1) continue;
        for(j; j<=temp; j++){
            ans.push_back("+");
            s.push(j);
        }
        if(s.top()!=temp){
            ans.clear();
            ans.push_back("NO");
            check = 1;
        }
        else{
            ans.push_back("-");
            s.pop();
        }
    }

    for(auto iter: ans){
        cout<<iter<<'\n';
    }
    return 0;
}