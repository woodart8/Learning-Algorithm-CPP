#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int,vector<int>> q;
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        if(temp){
            q.push(temp);
        }
        else{
            if(!q.empty()){
                v.push_back(q.top());
                q.pop();
            }
            else{
                v.push_back(0);
            }
        }
    }

    for(auto it: v){
        cout<<it<<'\n';
    }
}