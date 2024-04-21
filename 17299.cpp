#include <iostream>
#include <stack>

using namespace std;

int N;
int a[1000001]; //숫자들
int m[1000001]; //각각의 숫자 나온 횟수
int ans[1000001]; //정답
stack<pair<int,int>> s; // first : 나온 횟수, second : 숫자

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        int num;
        cin >> num;
        a[i] = num;
        m[num]++;
    }

    for(int i=N; i>=1; i--) {
        while(!s.empty() && s.top().first <= m[a[i]]) {
            s.pop();
        }
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top().second;
        s.push({m[a[i]], a[i]});
    }

    for(int i=1; i<=N; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}