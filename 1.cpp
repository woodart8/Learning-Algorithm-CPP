#include <iostream>
#include <string>
#include <algorithm>
#define BASE 25000
using namespace std;

double n[4];

int main(){
    cout<<"WRITE POINT"<<'\n';

    for(int i=0; i<4; i++){
        cin>>n[i];
        n[i]=(n[i]-BASE)/1000;
    }

    n[3]-=20;
    n[2]-=10;
    n[1]+=10;
    n[0]+=20;

    for(int i=0; i<4; i++){
        cout<<i+1<<": "<<n[i]<<'\n';
    }

    while(1){
        string check = "";
        cin>>check;
        if(check == "end" || check == "End" || check == "END"){
            break;
        }
    }
    
    return 0;
}