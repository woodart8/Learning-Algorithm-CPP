#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    string s;
    map<string,int> m;
    string name[100001];
    cin>>N>>M;

    for(int i=1; i<=N; i++){
        cin>>s;
        name[i]=s;
        m.insert(make_pair(s,i));
    }

    for(int i=1; i<=M; i++){
        cin>>s;
        if(isdigit(s[0])==true){
            int n = stoi(s);
            cout<<name[n]<<'\n';
        }
        else{
            auto it = m.find(s);
            cout << it->second<<'\n';
        }
    }

    return 0;
}