#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    long long a=0,b=0,c=0;
    long long m = 1e18;
    for(int i=0; i<N-2; i++){
        int l = i+1;
        int r = N-1;
        while(l<r) {
            long long sum = (long long)v[i] + v[l] + v[r];
            if(abs(sum) < m) {
                m = abs(sum);
                a = v[i];
                b = v[l];
                c = v[r];
            }
            if(sum < 0) l++;
            else r--;
        }
    }

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}