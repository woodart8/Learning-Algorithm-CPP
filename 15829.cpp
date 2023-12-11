#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    string s;
    cin>>s;
    int temp=1;
    for(int i=0; i<n; i++){
        sum+=((s[i]-'a'+1)*temp)%1234567891;
        temp*=31;
    }
    sum%=1234567891;

    cout<<sum<<endl;
    return 0;
}