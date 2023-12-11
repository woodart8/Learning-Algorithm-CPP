#include <iostream>

using namespace std;

int main(){
    int n;
    int count_five=0;
    cin>>n;
    for(int i=n; i>1; i--){
        if(i%5==0){
            count_five++;
        }
        if(i%25==0){
            count_five++;
        }
        if(i%125==0){
            count_five++;
        }
    }
    cout<<count_five<<'\n';
    return 0;
}