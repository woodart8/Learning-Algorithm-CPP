#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
deque<int> dq;
queue<int> q;
int ans = 0;

void func1() {
    dq.pop_front();
    q.pop();
}

void func2() {
    int temp = dq.front();
    dq.pop_front();
    dq.push_back(temp);
    ans++;
}

void func3() {
    int temp = dq.back();
    dq.pop_back();
    dq.push_front(temp);
    ans++;
}

int main() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        dq.push_back(i);
    }

    for(int i=0; i<M; i++) {
        int num;
        cin >> num;
        q.push(num);
    }

    while(!q.empty()) {
        if(q.front() == dq.front()) {
            func1();
            continue;
        }
        
        int idx = find(dq.begin(), dq.end(), q.front()) - dq.begin();
        if(idx <= dq.size()/2) {
            func2();
        }
        else {
            func3();
        }
    }

    cout << ans << endl;
    return 0;
}