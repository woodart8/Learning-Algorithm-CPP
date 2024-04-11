#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
vector<int> temp;
int check[1000001];
stack<int> st;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    temp.push_back(v[0]);
    for(int i=1; i<N; i++) {
        if(temp.back() < v[i]) {
            temp.push_back(v[i]);
            check[i] = temp.size()-1;
        }
        else {
            int idx = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            temp[idx] = v[i];
            check[i] = idx;
        }
    }
    cout << temp.size() << endl;
    
    int cnt = temp.size() - 1;
    for(int i=N-1; i>=0; i--) {
        if(check[i] == cnt) {
            st.push(v[i]);
            cnt--;
        }
    }

    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}