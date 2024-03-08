#include <iostream>
#include <vector>
using namespace std;

int prime[1000001];
vector<int> v;

void sosu(int n) {
    prime[0] = 1;
    prime[1] = 1;
    for(int i=2; i*i <= n; i++) {
        if(prime[i] == 0) {
            for(int j=i*i; j <= n; j+=i) {
                prime[j] = 1;
            }
        }
    }

    for(int i=2; i<n; i++) {
        if(prime[i] == 0) v.push_back(i);
    }
}   


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    sosu(1000000);
    while(1) {
        cin >> n;
        if(n == 0) return 0;
        int a, b;
        for(int i=0; i < v.size(); i++) {
            a = v[i];
            b = n - v[i];
            if(prime[b] == 0) break;
        }
        if(prime[b] == 0) printf("%d = %d + %d\n",n,a,b);
        else printf("Goldbach's conjecture is wrong.\n");
    }
}