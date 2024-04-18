#include <iostream>
#include <vector>
#include <stack>

using namespace std;



int main() {
    while(1) {
        int N;
        cin >> N;
        if(N==0) break;

        stack<pair<int,int>> s;
        long long ans = 0;
        for(int i=0; i<N; i++) {
            int height;
            cin >> height;
            int idx = i;
            while(!s.empty() && s.top().first >= height) {
                ans = max(ans, 1LL * (i - s.top().second) * s.top().first);
                idx = s.top().second;
                s.pop();
            }
            s.push({height, idx});   
        }
        while(!s.empty()) {
            ans = max(ans, 1LL * (N - s.top().second) * s.top().first);
            s.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}