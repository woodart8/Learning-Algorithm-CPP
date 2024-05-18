#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int map[21][21];
int region[21][21];
int population[6];
int ans = 1e9;

void fill_region(int x, int y, int d1, int d2) {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            region[i][j] = 5;
        }
    }

    int Area = (x == 1) ? 1 : 0;
    for(int i=1; i<x+d1; i++) {
        if(i >= x) Area++; 
        for(int j=1; j<=y-Area; j++) {
            region[i][j] = 1;
        }
    }

    Area = (y+d2 == N) ? 1 : 0;
    for(int i=N; i>y; i--) {
        if(i <= y+d2) Area++;
        for(int j=1; j<=x+d2-Area; j++) {
            region[j][i] = 2;
        }
    }

    Area = (y-d1 == 1) ? 1 : 0;
    for(int i=1; i<y-d1+d2; i++) {
        if(i >= y-d1) Area++;
        for(int j=N; j>=x+d1+Area; j--) {
            region[j][i] = 3;
        }
    }

    Area = (x+d1+d2 == N) ? 1 : 0;
    for(int i=N; i>x+d2; i--) {
        if(i <= x+d1+d2) Area++;
        for(int j=N; j>=y-d1+d2+Area; j--) {
            region[i][j] = 4;
        }
    }
}

void Bruteforce(int x, int y, int d1, int d2) {
    if(x < 1 || x+d1+d2 > N) return;
    if(y-d1 < 1 || y+d2 > N) return;

    memset(region, 0, sizeof(region));
    memset(population, 0, sizeof(population));

    fill_region(x,y,d1,d2);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            population[region[i][j]] += map[i][j];
        }
    }
    sort(population+1, population+6);
    ans = min(ans, population[5]-population[1]);
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=2; j<=N; j++) {
            for(int d1 = 1; d1 < j; d1++) {
                for(int d2 = 1; d2 <= N-j; d2++) {
                    Bruteforce(i,j,d1,d2);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}