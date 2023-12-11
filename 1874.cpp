#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;

void push(int num){
    v.push_back(num);
}

int top(){
    if(v.size()==0){
        return -1;
    }
    return *(v.end()-1);
}

int size(){
    return v.size();
}

int empty(){
    if(v.size()==0)
        return 1;
    else return 0;
}

void pop(){
    if(v.size()==0){
        return;
    }
    v.pop_back();
}

int main(){
    int n,temp,j=1,check = 0;
    vector<string> ans;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(check==1) continue;
        for(j; j<=temp; j++){
            ans.push_back("+");
            push(j);
        }
        if(top()!=temp){
            ans.clear();
            ans.push_back("NO");
            check = 1;
        }
        else{
            ans.push_back("-");
            pop();
        }
    }

    for(auto iter: ans){
        cout<<iter<<'\n';
    }
    return 0;
}