#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    double sum  = 0;
    for(auto it: v){
        sum+=it;
    }

    sort(v.begin(),v.end());

    int max = 0;
    int max_count = 0;
    int maxi = 0;
    vector<int> w;
    for(int i=0; i<v.size(); i++){
        int num = upper_bound(v.begin(), v.end(), v[i])-lower_bound(v.begin(), v.end(), v[i])+1;
        if(max_count<num){
            max = v[i];
            max_count = num;
            maxi = i;
            w.clear();
            w.push_back(max);
        }
        else if(max_count==num && v[i]!=max){
            w.push_back(v[i]);
        }
    }
    cout<<fixed;
    cout.precision(0);
    if((int)sum/n == 0)
        cout<<abs(sum/n)<<'\n';
    else
        cout<<sum/n<<'\n';
    cout<<v[(v.size()-1)/2]<<'\n';
    if(w.size() == 1) cout<<w[0]<<'\n';
    else cout<<w[1]<<'\n';
    cout<<*(v.end()-1)-*v.begin()<<'\n';

    return 0;
}