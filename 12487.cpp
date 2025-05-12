#include <iostream>
#include <vector>

using namespace std;

bool is_prime[101];
vector<int> primes;

void init(int n){
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    for(int i = 3; i <= n; i++) 
        is_prime[i] = i % 2;
    for(int i = 3; i*i <= n; i+=2){
        if (is_prime[i])
            for(int j = i*i; j <= n; j+=i)
                is_prime[j] = false;
    }
    for(int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
}

int Discrete_log(int p, int n){
    int cnt = 0, prod = 1;
    while (prod <= n){
        prod *= p;
        cnt++;
    }
    return cnt - 1;
}

int main (){
    init(100);

    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++){
        int n, ans = 1;
        cin >> n;

        if (n == 1){
            cout << "Case #" << cases << ": "  << 0 << "\n";
            continue;
        }

        for(int i = 0; primes[i]*primes[i] <= n; i++){
            ans += Discrete_log(primes[i], n) - 1;
        }

        cout << "Case #" << cases << ": "  << ans << "\n";
    }
    

    return 0;
}