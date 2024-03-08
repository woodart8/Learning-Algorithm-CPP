#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<pair<int, int>> menu;
int p[10];

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> p[i];
        menu.push_back({p[i], i});
    }
    cin >> M;

    sort(menu.begin(), menu.end());

    string s = "";
    if(N == 1) {
        cout << "0";
        return 0;
    }

    if(menu[0].second != 0){
        int cnt = M/menu[0].first;
        for(int i=0; i<cnt; i++) s += to_string(menu[0].second);
        M -= cnt * menu[0].first;
    }else{
        int m = M - menu[1].first;
        if(m<0) {
            cout << "0";
            return 0;
        }
        s += to_string(menu[1].second);
        int cnt = m/menu[0].first;
        for(int i=0; i<cnt; i++) s += to_string(menu[0].second);
        M  = m - cnt * menu[0].first;
    }

    for(int i=0; i<s.size(); i++){
        bool ok = false;
        int cur = p[s[i] - '0'];
        for(int j=N-1; j>=0; j--){
            if(M - (p[j]-cur) >= 0){
                M -= p[j]-cur;
                ok = 1;
                s[i] = j + '0';
            }
            if(ok) break;
        }
        if(!ok) break;
    }   

    cout << s;
    return 0;
}