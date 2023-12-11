#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool remote[10];

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        remote[temp]=true;
    }

    int add = n;
    int minus = n;
    int check = 0;

    while(!check){
        int t=add;
        if(t>999999){
            add=987654321;
            break;
        }
        do{
            if(remote[t%10]){
                check=1;
                break;
            }
            t/=10;
        }while(t);
        if(!check){
            break;
        }
        else{
            add++;
            check=0;
        }
    }

    while(!check){
        int t=minus;
        if(t<0){
            minus=987654321;
            break;
        }
        do{
            if(remote[t%10]){
                check=1;
                break;
            }
            t/=10;
        }while(t);
        if(!check){
            break;
        }
        else{
        minus--;
        check=0;
    }
}

    string add_s = to_string(add);
    string minus_s = to_string(minus);
    cout<<min(abs(100-n),(int)min(abs(add-n)+add_s.size(),abs(minus-n)+minus_s.size()))<<'\n';
    return 0;
}