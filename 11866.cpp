#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> ans;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }

    int index = (k-1)%v.size();
    while(v.size()>0){
        ans.push_back(v[index]);
        v.erase(v.begin()+index);
        if(v.size()==0) break;
        index=index+k-1;
        index=index%v.size();
    }

    cout<<'<';
    for(auto iter:ans){
        if(iter==*(ans.end()-1)){
            cout<<iter<<'>';
            break;
        }
        cout<<iter<<", ";
    }

    return 0;
}