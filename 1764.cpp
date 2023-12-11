#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<string> heard;
vector<string> seen;
vector<string> ans;

int main(){
    string s;

    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>s;
        heard.push_back(s);
    }
    for(int i=0; i<M; i++){
        cin>>s;
        seen.push_back(s);
    }

    sort(heard.begin(),heard.end());
    sort(seen.begin(),seen.end());

    for(auto iter: heard){
        int start = 0;
        int end = seen.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(seen[mid]<iter){
                start = mid+1;
            }
            else if(seen[mid]>iter){
                end = mid-1;
            }
            else{
                ans.push_back(iter);
                break;
            }
        }
    }

    cout<<ans.size()<<'\n';
    for(auto iter: ans){
        cout<<iter<<'\n';
    }

    return 0;
}