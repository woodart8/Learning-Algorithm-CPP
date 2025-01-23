#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
double dp[65536];

void input() {
    cin >> N;
    v.resize(N);
    for (int i=0; i<N; i++)
        cin >> v[i];
}

double calcS(int a, int b, int c) {
    return (double)(a+b+c)/2;
}

double calcArea(double s, int a, int b, int c) {
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double calcSum(int state) {
    if (dp[state] > 0) return dp[state];

    for (int i=0; i<v.size()-2; i++) {
        if (state & (1 << i)) continue;
        for (int j=i+1; j<v.size()-1; j++) {
            if (state & (1 << j)) continue;
            for (int k=j+1; k<v.size(); k++) {
                if (state & (1 << k)) continue;
                if (v[i] + v[j] > v[k]) {
                    double s = calcS(v[i], v[j], v[k]);
                    double area = calcArea(s, v[i], v[j], v[k]);
                    int nState = state | (1 << i) | (1 << j) | (1 << k);
                    area += calcSum(nState);
                    dp[state] = max(dp[state], area); 
                }
            }
        }
    }

    return dp[state];
}

void solve() {
    sort(v.begin(), v.end());

    cout.precision(16);
    cout << fixed;
    cout << calcSum(0); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}