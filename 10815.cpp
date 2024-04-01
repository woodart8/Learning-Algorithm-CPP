#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    int num=0;
    for(int i=0; i<N; i++) {
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> num;
        if(binary_search(a.begin(), a.end(), num)) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    return 0;
}