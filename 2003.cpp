#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> v;

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int s=0, e=0, sum=0, count=0;
    while(s<=e) {
        if(sum >= M) {
            if(sum == M) count++;
            sum-=v[s++];
        }
        else if(e == N) break;
        else {
            sum+=v[e++];
        }
    }
    cout << count << endl;
    return 0;
}