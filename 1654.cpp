#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

int k, n;
int* arr;

long long find(long long start, long long end) {
    if(start>end) return end;
    long long mid = (start + end) / 2;
    int count = 0;
    for (int i = 0; i < k; i++) {
        count += arr[i] / mid;
    }
    
    if (count < n) {
        return find(start, mid-1);
    }
    else{
        return find(mid+1, end);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> k >> n;
    arr = new int[k];
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int count = 0;
    long long start = 1;
    long long end = sum / n + 1;

    cout << find(start, end);

}