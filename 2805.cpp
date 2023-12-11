#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n,m;
vector<int> v;

long long find(long long start, long long end){
    if(start>end) return end;
    long long mid = (start+end)/2;
    long long count = 0;
    for(int i=0; i<n; i++){
        if(v[i]>mid)
            count+=v[i]-mid;
    }
    if(count<m){
        return find(start, mid-1);
    }
    else{
        return find(mid+1,end);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;

    int temp;

    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout<<find(0,*(v.end()-1));

    return 0;
}