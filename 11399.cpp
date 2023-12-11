#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            sum+=v[j];
        }
    }

    cout<<sum<<'\n';
    return 0;
}