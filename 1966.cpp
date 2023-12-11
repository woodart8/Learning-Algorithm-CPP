#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int n, size, index, weight;
    vector<pair<int,int>> v;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>size>>index;
        for(int j=0; j<size; j++){
            cin>>weight;
            v.push_back(make_pair(j,weight));
        }
        for(int x=0; x<v.size()-1;x++){
            int k=x+1;
            while(k<v.size()){
                if(v[x].second<v[k].second){
                    v.push_back(v[x]);
                    v.erase(v.begin()+x);
                    k = x+1;
                    continue;
                }
                k++;
            }
        }

        for(int l=0; l<v.size(); l++){
            if(v[l].first == index){
                cout<<l+1<<'\n';
                v.clear();
                break;
            }
        }
    }

    return 0;
}