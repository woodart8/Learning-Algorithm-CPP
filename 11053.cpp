#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
vector<int> t;
int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    t.push_back(v[0]);
    for (int i=1; i<N; i++) {
        if (t.back() < v[i]) {
            t.push_back(v[i]);
        } else {
            int idx = lower_bound(t.begin(), t.end(), v[i]) - t.begin();
            t[idx] = v[i];
        }
    }

    cout << t.size() << '\n';

    for (int i=0; i<t.size(); i++) {
        cout << t[i] << ' ';
    }
    return 0;
}