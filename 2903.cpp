#include <iostream>

using namespace std;

int N;
int main() {
    cin >> N;
    int mul = 1;
    for(int i=1; i<=N; i++) {
        mul *= 2;
    }
    cout << (mul+1)*(mul+1);
    //2^n+1
    return 0;
}