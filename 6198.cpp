#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> s;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        int h;
        cin >> h;
        while(!s.empty() && s.top() <= h) {
            s.pop();
        }
        ans += s.size();
        s.push(h);
    }

    cout << ans << endl;
    return 0;
}