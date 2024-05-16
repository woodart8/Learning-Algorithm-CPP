#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int N;
pair<ll,ll> xa[100001];
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ll sum=0;
    for(int i=1;i<=N;i++) {
        cin >> xa[i].first >> xa[i].second;
        sum+=xa[i].second;
    }
    sort(xa+1,xa+N+1);
 
    ll cur=0;
    for(int i=1;i<=N;i++){
        cur+=xa[i].second;
        if(cur>=(sum+1)/2) {
            cout << xa[i].first;
            break;
        }
    }
}