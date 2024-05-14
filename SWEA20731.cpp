#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 490
int T;
char map[MAX][MAX];
char arr[MAX][MAX];

int gcd(int a, int b) {
    if(a < b) swap(a,b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    cin >> T;
    int t = 1;

    for(int i=1; i<=MAX-1; i++) {
        for(int j=1; j<=MAX-1; j++) {
            if(gcd(i,j) == 1) arr[i][j] = '1';
            else arr[i][j] = '?';
        }
    }

    while(t <= T) {
        int N;
        cin >> N;
        bool check = true;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                cin >> map[i][j];
            }
        }

        for(int k=0; k<=MAX-51; k++) {
            check = true;
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=N; j++) {
                    if(arr[i+k][j+k] != map[i][j]) {
                        check = false;
                    }
                    if(!check) break;
                }
                if(!check) break;
            }
            if(check) break;
        }

        if(check) cout << "#" << t << " YES" << '\n';
        else cout << "#" << t << " NO" << '\n';
        t++;
    }
    return 0;
}