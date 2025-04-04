#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int X,Y,D,T;

void input() {
    scanf("%d %d %d %d", &X, &Y, &D, &T);
}

double calcD(int x, int y) {
    return sqrt(x*x + y*y);
}

void solve() {
    double d = calcD(X, Y);
    if (d > D) {
        if (D/T >= 1) {
            double temp = 0;
            while (d > 2*D) {
                d -= D;
                temp += T;
            }
            if (d > D) printf("%.9lf\n", temp + min((double)T*2, T+d-D));
            else if (d == D) printf("%.9lf\n", temp + T);
            else printf("%.9lf\n", temp + min((double)T*2, T+D-d));
        } 
        else printf("%.9lf\n", d);
    } 
    // 직선거리가 점프거리보다 먼 경우
    // D/T >= 1 즉 걸어가는거보다 점프 효율이 좋을 경우
    // 일단 남은 거리가 점프거리의 두 배와 같거나 작아질때까지 점프
    // 1. 남은 직선거리가 점프거리보다 먼 경우 점프 두번으로 돌아서 가거나, 한번 점프한 뒤 걸어서 가기
    // 2. 남은 직선거리와 점프거리가 같은 경우 점프 효율이 좋으므로 점프하기
    // 3. 남은 직선거리보다 점프거리가 먼 경우 점프 두번으로 돌아서 가거나, 점프해서 집을 넘어간뒤 걸어서 가기 

    else if (d == D) {
        if (d < T) printf("%.9lf\n", d);
        else printf("%.9lf\n", (double)T);
    } 
    // 직선거리와 점프거리가 같은 경우
    // 1. 걸어가는게 점프보다 빠를 경우 걸어가기
    // 2. 점프가 걸어가는거보다 빠를 경우 점프 

    else printf("%.9lf\n", min(min((double)T*2, T+D-d), d));
    // 직선거리보다 점프거리가 먼 경우
    // 1. 점프 두번으로 돌아서 가기
    // 2. 점프 한번으로 집을 넘어간 뒤 걸어서 집으로 가기
    // 3. 그냥 걸어서 가기
}

int main() {
    input();
    solve();

    return 0;
}