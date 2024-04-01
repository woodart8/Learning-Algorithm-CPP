#include <iostream>
#include <vector>

using namespace std;

int N,K;
vector<int> v;

int main() {
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int sum = 0;
    for(int i=0; i<K; i++) {
        sum+=v[i];
    }
    int j=0;
    int maxSum = sum;
    for(int i=K; i<N; i++) {
        sum-=v[j];
        sum+=v[i];
        maxSum = max(maxSum, sum);
        j++;
    }

    cout << maxSum << endl;
    return 0;
}