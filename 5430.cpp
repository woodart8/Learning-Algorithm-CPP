#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin>>test_case;
    for(int i=0; i<test_case; i++){
        int n;
        vector<int> v;
        string s,func,temp="";
        bool reverse = false;
        bool error = false;
        cin>>func;
        cin>>n;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            if(isdigit(s[j])){
                temp+=s[j];
            }
            else {
                if(!temp.empty()){
                    v.push_back(stoi(temp));
                    temp="";
                }
            }
        }
        
        for(int j=0; j<func.size(); j++){
            if(func[j]=='R'){
                if(reverse==false){
                    reverse = true;
                }
                else{
                    reverse = false;
                }
            }
            else{
                if(v.empty()){
                    cout<<"error"<<'\n';
                    error=true;
                    break;
                }
                if(reverse)
                    v.pop_back();
                else
                    v.erase(v.begin());
            }
        }

        if (!error) {
            cout << '[';
        }
        if (reverse && !v.empty()) {
            for (auto o = v.rbegin(); o != v.rend(); o++) {
                if (o == v.rend() - 1)
                    cout << *o;
                else
                cout << *o << ',';
            }
        }
        else if (!reverse&&!v.empty()){
            for (auto o = v.begin(); o != v.end(); o++) {
                if (o == v.end() - 1)
                    cout << *o;
                else
                cout << *o << ',';
            }
        }
        if (!error) {
            cout << "]\n";
        }
    }
}