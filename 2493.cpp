#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int,int>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        int h;
        cin >> h;
        while(!s.empty() && s.top().first < h) {
            s.pop();
        }
        if(s.empty()) cout << 0 << ' ';
        else cout << s.top().second << ' ';
        s.push({h,i});
    }

    return 0;
}