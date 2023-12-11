#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    while(1){
        string s;
        cin>>s;
        if(s=="0"){
            break;
        }
        string t = s;
        reverse(s.begin(), s.end());

        if(s==t){
            cout<<"yes"<<'\n';
        }
        else{
            cout<<"no"<<'\n';
        }
    }
    return 0;
}