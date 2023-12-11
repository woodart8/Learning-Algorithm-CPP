#include <iostream>

using namespace std;

int n;
int dist[301];
int value[301];

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>value[i];
    }

    dist[1]=value[1];
    dist[2]=value[1]+value[2];
    for(int i=3; i<=n; i++){
        dist[i] = value[i]+max(dist[i-2],dist[i-3]+value[i-1]);
    }
    cout<<dist[n];
}