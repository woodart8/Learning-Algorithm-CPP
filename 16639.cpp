#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int N;
int dp[20];
int maxarr[10][10];
int minarr[10][10];

int calculate(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
    }
}

int main() {
    cin >> N;
    char ch[N];
    int num = N/2+1;
    for(int i=0; i<N; i++) {
        cin >> ch[i];
    }
    
    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            maxarr[i][j] = INT32_MIN;
            minarr[i][j] = INT32_MAX;
        }
    }

    for(int i=0; i<num; i++) {
        maxarr[i][i] = minarr[i][i] = ch[i*2] - '0';
    }

    for(int j=1; j<num; j++) {
        for(int i=0; i<num-j; i++) {
            for(int k=1; k<=j; k++) {
                vector<int> v;
                char op = ch[(i+k-1)*2+1];
                v.push_back(calculate(maxarr[i][i+k-1], maxarr[i+k][i+j], op));
                v.push_back(calculate(maxarr[i][i+k-1], minarr[i+k][i+j], op));
                v.push_back(calculate(minarr[i][i+k-1], maxarr[i+k][i+j], op));
                v.push_back(calculate(minarr[i][i+k-1], minarr[i+k][i+j], op));

                sort(v.begin(), v.end());

                maxarr[i][i+j] = max(maxarr[i][i+j], v[3]);
                minarr[i][i+j] = min(minarr[i][i+j], v[0]);
            }
        }
    }

    cout << maxarr[0][num-1] << endl;

    return 0;
}
