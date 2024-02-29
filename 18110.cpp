#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

int main() {
    cin >> N;
    if(N == 0) {
        cout << 0;
        return 0;
    }
    vector<int> v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cut = round(float(N) * 15 / 100);
    float sum = 0;

    for(int i=0+cut; i<N-cut; i++){
        sum+=v[i];
    }
    cout << round(sum / (N-2*cut));
    return 0;
}