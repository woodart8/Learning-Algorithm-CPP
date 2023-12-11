#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n, size,tmp,minimum=1000*1000*1000;
    int arr[1001] = {0};

    cin>>n>>size;
    for(int i=0; i<size; i++){
        cin>>tmp;
        arr[tmp]=1;
    }

    for(int i=1; i<1001; i++){
        if(arr[i]==1) continue;
        for(int j=1; j<1001; j++){
            if(arr[j]==1) continue;
            for(int k=1; k<=1001; k++){
                if(arr[k]==1) continue;
                minimum = min(minimum,abs(n-i*j*k));
                if(n-i*j*k<-1) break;
            }
        }
    }

    cout<<minimum<<endl;
    return 0;
}