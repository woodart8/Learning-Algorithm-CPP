#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

double solve(vector<double> x, vector<double> y, int n){
    double answer = 0.0;
    for(int i = 2;i<n;i++){
        answer += x[0] * y[i-1] + x[i-1] * y[i] + x[i] * y[0];
        answer -= x[i-1] * y[0] + x[i] * y[i-1] + x[0] * y[i];
    }
    return answer;
}

int main(){
    int n;
    cin>>n;
    vector<double> x(n);
    vector<double> y(n);
    for(int i = 0;i<n;i++){
        cin>>x[i];
        cin>>y[i];
    }
    double answer = solve(x,y,n) / 2;
    printf("%.1f\n",abs(answer));
    return 0;
}