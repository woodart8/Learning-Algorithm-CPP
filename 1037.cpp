#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), cmp);

    cout << v.front()*v.back();
    return 0;
}