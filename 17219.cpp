#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N,M;
map<string,string> m;
vector<string> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i=0; i<N; i++){
        string s,t;
        cin>>s>>t;
        m.insert({s,t});
    }

    for(int i=0; i<M; i++){
        string u;
        cin>>u;
        auto it = m.find(u);
        if(it!=m.end()){
            ans.push_back(it->second);
        }
    }

    for(auto it:ans){
        cout<<it<<'\n';
    }
    return 0;
}